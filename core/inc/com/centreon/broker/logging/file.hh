/*
** Copyright 2009-2012 Centreon
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** For more information : contact@centreon.com
*/

#ifndef CCB_LOGGING_FILE_HH
#  define CCB_LOGGING_FILE_HH

#  include <QFile>
#  include "com/centreon/broker/logging/backend.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace              logging {
  /**
   *  @class file file.hh "com/centreon/broker/logging/file.hh"
   *  @brief Log messages to a file.
   *
   *  Log messages to a file.
   */
  class                file : public backend {
  public:
                       file(
                         QString const& path,
                         unsigned long long max = 100000000000ull);
                       file(FILE* special);
                       ~file();
    void               log_msg(
                         char const* msg,
                         unsigned int len,
                         type log_type,
                         level l) throw ();
    static bool        with_flush() throw ();
    static void        with_flush(bool enable) throw ();
    static bool        with_thread_id() throw ();
    static void        with_thread_id(bool enable) throw ();
    static bool        with_timestamp() throw ();
    static void        with_timestamp(bool enable) throw ();
    static bool        with_human_redable_timestamp() throw();
    static void        with_human_redable_timestamp(bool enable) throw();

  private:
                       file(file const& f);
    file&              operator=(file const& f);
    void               _reopen();
    void               _write(char const* data) throw ();

    QFile              _file;
    unsigned long long _max;
    bool               _special;
    static bool        _with_flush;
    static bool        _with_timestamp;
    static bool        _with_human_readable_timestamp;
    static bool        _with_thread_id;
    unsigned long long _written;
  };
}

CCB_END()

#endif // !CCB_LOGGING_FILE_HH
