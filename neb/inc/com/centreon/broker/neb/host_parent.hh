/*
** Copyright 2009-2011 Merethis
** This file is part of Centreon Broker.
**
** Centreon Broker is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Broker is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Broker. If not, see
** <http://www.gnu.org/licenses/>.
*/

#ifndef CCB_NEB_HOST_PARENT_HH_
# define CCB_NEB_HOST_PARENT_HH_

# include "com/centreon/broker/io/data.hh"

namespace                com {
  namespace              centreon {
    namespace            broker {
      namespace          neb {
        /**
         *  @class host_parent host_parent.hh "com/centreon/broker/neb/host_parent.hh"
         *  @brief Define a parent of a host.
         *
         *  Define a certain host to be the parent of another host.
         */
        class            host_parent : public io::data {
         public:
          unsigned int   host_id;
          unsigned int   parent_id;
                         host_parent();
                         host_parent(host_parent const& hp);
                         ~host_parent();
          host_parent&   operator=(host_parent const& hp);
          QString const& type() const;
        };
      }
    }
  }
}

#endif /* !CCB_NEB_HOST_PARENT_HH_ */