/*
** Copyright 2012-2013 Centreon
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

#ifndef CC_CONCURRENCY_THREAD_WIN32_HH
#  define CC_CONCURRENCY_THREAD_WIN32_HH

#  include <windows.h>
#  include "com/centreon/namespace.hh"

CC_BEGIN()

namespace            concurrency {
  typedef HANDLE thread_id;

  /**
   *  @class thread thread_win32.hh "com/centreon/concurrency/thread.hh"
   *  @brief Win32 thread wrapper.
   *
   *  Wrap Win32 threads in a nice and easy to use class.
   */
  class              thread {
  public:
                     thread();
    virtual          ~thread() throw ();
    void             exec();
    static thread_id get_current_id() throw ();
    static void      msleep(unsigned long msecs);
    static void      nsleep(unsigned long nsecs);
    static void      sleep(unsigned long secs);
    static void      usleep(unsigned long usecs);
    void             wait();
    bool             wait(unsigned long timeout);
    static void      yield() throw ();

  protected:
    virtual void     _run() = 0;

  private:
                     thread(thread const& t);
    thread&          operator=(thread const& t);
    void             _close() throw ();
    static DWORD     _helper(void* data);

    HANDLE           _th;
  };
}

CC_END()

#endif // !CC_CONCURRENCY_THREAD_WIN32_HH
