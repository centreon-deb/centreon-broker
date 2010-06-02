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

#ifndef INTERFACE_DB_DESTINATION_H_
# define INTERFACE_DB_DESTINATION_H_

# include <string>
# include <soci.h>
# include "events/events.h"
# include "interface/destination.h"

namespace                         Interface
{
  namespace                       DB
  {
    /**
     *  \class Destination destination.h "interface/db/destination.h"
     *  \brief Insert/update events in a database.
     *
     *  Handle insertion of events in their generic form into a database.
     */
    class                         Destination : public Interface::Destination
    {
     public:
      enum                        DB
      {
        UNKNOWN = 0,
        MYSQL,
        ORACLE,
        POSTGRESQL
      };

     private:
      static void                    (Destination::* processing_table[])(const Events::Event&);
      Events::Acknowledgement        acknowledgement_;
      std::auto_ptr<soci::statement> acknowledgement_stmt_;
      Events::Comment                comment_;
      std::auto_ptr<soci::statement> comment_stmt_;
      Events::Downtime               downtime_;
      std::auto_ptr<soci::statement> downtime_stmt_;
      Events::HostCheck              host_check_;
      std::auto_ptr<soci::statement> host_check_stmt_;
      Events::HostStatus             host_status_;
      std::auto_ptr<soci::statement> host_status_stmt_;
      Events::Issue                  issue_;
      std::auto_ptr<soci::statement> issue_stmt_;
      Events::ProgramStatus          program_status_;
      std::auto_ptr<soci::statement> program_status_stmt_;
      Events::ServiceCheck           service_check_;
      std::auto_ptr<soci::statement> service_check_stmt_;
      Events::ServiceStatus          service_status_;
      std::auto_ptr<soci::statement> service_status_stmt_;
      std::auto_ptr<soci::session> conn_; // Connection object is necessary after statements.
                                  Destination(const Destination& destination);
      Destination&                operator=(const Destination& destination);
      void                        CleanTables(int instance_id);
      template                    <typename T>
      void                        Insert(const T& t);
      template                    <typename T>
      void                        PrepareUpdate(std::auto_ptr<soci::statement>& st,
                                                T& t,
                                                const std::vector<std::string>& id);
      void                        ProcessAcknowledgement(const Events::Event& event);
      void                        ProcessComment(const Events::Event& event);
      void                        ProcessDowntime(const Events::Event& event);
      void                        ProcessHost(const Events::Event& event);
      void                        ProcessHostCheck(const Events::Event& event);
      void                        ProcessHostDependency(const Events::Event& event);
      void                        ProcessHostGroup(const Events::Event& event);
      void                        ProcessHostGroupMember(const Events::Event& event);
      void                        ProcessHostParent(const Events::Event& event);
      void                        ProcessHostStatus(const Events::Event& event);
      void                        ProcessIssue(const Events::Event& event);
      void                        ProcessIssueUpdate(const Events::Event& event);
      void                        ProcessLog(const Events::Event& event);
      void                        ProcessProgram(const Events::Event& event);
      void                        ProcessProgramStatus(const Events::Event& event);
      void                        ProcessService(const Events::Event& event);
      void                        ProcessServiceCheck(const Events::Event& event);
      void                        ProcessServiceDependency(const Events::Event& event);
      void                        ProcessServiceGroup(const Events::Event& event);
      void                        ProcessServiceGroupMember(const Events::Event& event);
      void                        ProcessServiceStatus(const Events::Event& event);

     public:
                                  Destination();
                                  ~Destination();
      void                        Close();
      void                        Event(Events::Event* event);
      void                        Connect(DB db_type,
                                          const std::string& db,
                                          const std::string& host,
                                          const std::string& user,
                                          const std::string& pass);
    };
  }
}

#endif /* !INTERFACE_DB_DESTINATION_H_ */