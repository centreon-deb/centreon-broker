/*
** Copyright 2014 Centreon
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

#ifndef CCB_BAM_KPI_BA_HH
#  define CCB_BAM_KPI_BA_HH

#  include "com/centreon/broker/bam/kpi.hh"
#  include "com/centreon/broker/bam/kpi_event.hh"
#  include "com/centreon/broker/io/stream.hh"
#  include "com/centreon/broker/misc/shared_ptr.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace   bam {
  // Forward declaration.
  class     ba;
  class     computable;

  /**
   *  @class kpi_ba kpi_ba.hh "com/centreon/broker/bam/kpi_ba.hh"
   *  @brief BA as a KPI.
   *
   *  This class allows you to use a BA (class ba) as a KPI for another
   *  BA.
   */
  class     kpi_ba : public kpi {
  public:
            kpi_ba();
            kpi_ba(kpi_ba const& right);
            ~kpi_ba();
    kpi_ba& operator=(kpi_ba const& right);
    bool    child_has_update(
              computable* child,
              io::stream* visitor = NULL);
    double  get_impact_critical() const;
    double  get_impact_warning() const;
    void    impact_hard(impact_values& hard_impact);
    void    impact_soft(impact_values& soft_impact);
    void    link_ba(misc::shared_ptr<ba>& my_ba);
    void    set_impact_critical(double impact);
    void    set_impact_warning(double impact);
    void    unlink_ba();
    void    visit(io::stream* visitor);

  private:
    void    _fill_impact(
              impact_values& impact,
              short state,
              double acknowledgement,
              double downtime);
    void    _internal_copy(kpi_ba const& right);
    void    _open_new_event(
              io::stream* visitor,
              int impact,
              short ba_state,
              timestamp event_start_time);

    misc::shared_ptr<ba>
            _ba;
    double  _impact_critical;
    double  _impact_warning;
  };
}

CCB_END()

#endif // !CCB_BAM_KPI_BA_HH
