/*
**  Copyright 2009 MERETHIS
**  This file is part of CentreonBroker.
**
**  CentreonBroker is free software: you can redistribute it and/or modify it
**  under the terms of the GNU General Public License as published by the Free
**  Software Foundation, either version 2 of the License, or (at your option)
**  any later version.
**
**  CentreonBroker is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
**  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
**  for more details.
**
**  You should have received a copy of the GNU General Public License along
**  with CentreonBroker.  If not, see <http://www.gnu.org/licenses/>.
**
**  For more information : contact@centreon.com
*/

#ifndef EVENTS_GROUP_H_
# define EVENTS_GROUP_H_

# include <list>
# include <string>
# include "events/event.h"

namespace                  Events
{
  /**
   *  \class Group group.h "events/group.h"
   *  \brief Base of host and service group classes.
   *
   *  Nagios handles group. This can be service groups or host groups for
   *  example.
   *
   *  \see HostGroup
   *  \see ServiceGroup
   */
  class                    Group : public Event
  {
   private:
    void                   InternalCopy(const Group& group);

   public:
    std::string            action_url;
    std::string            alias;
    int                    instance_id;
    std::string            name;
    std::string            notes;
    std::string            notes_url;
                           Group();
                           Group(const Group& group);
    virtual                ~Group();
    Group&                 operator=(const Group& group);
  };
}

#endif /* !EVENTS_GROUP_H_ */