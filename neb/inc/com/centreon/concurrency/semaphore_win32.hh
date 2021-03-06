/*
** Copyright 2011-2013 Centreon
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

#ifndef CC_CONCURRENCY_SEMAPHORE_WIN32_HH
#  define CC_CONCURRENCY_SEMAPHORE_WIN32_HH

#  include <windows.h>
#  include "com/centreon/namespace.hh"

CC_BEGIN()

namespace      concurrency {
  /**
   *  @class semaphore semaphore_win32.hh "com/centreon/concurrency/semaphore.hh"
   *  @brief Implements a semaphore.
   *
   *  Win32 implementation of a semaphore.
   */
  class        semaphore {
  public:
               semaphore(unsigned int n = 0);
               ~semaphore() throw ();
    void       acquire();
    bool       acquire(unsigned long timeout);
    int        available();
    void       release();
    bool       try_acquire();

  private:
               semaphore(semaphore const& s);
    semaphore& operator=(semaphore const& s);

    HANDLE     _sem;
  };
}

CC_END()

#endif // !CC_CONCURRENCY_SEMAPHORE_WIN32_HH
