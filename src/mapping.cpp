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

#include "events/events.h"
#include "mapping.h"
#include "nagios/protoapi.h"

using namespace Events;

// Acknowledgement members mapping.
static const MappedData<Acknowledgement> acknowledgement_mapping[] =
  {
    MappedData<Acknowledgement>(
      &Acknowledgement::acknowledgement_type,
      NDO_DATA_ACKNOWLEDGEMENTTYPE,
      "acknowledgement_type"),
    MappedData<Acknowledgement>(
      &Acknowledgement::author,
      NDO_DATA_AUTHORNAME,
      "author_name"),
    MappedData<Acknowledgement>(
      &Acknowledgement::comment,
      NDO_DATA_COMMENT,
      "comment_data"),
    MappedData<Acknowledgement>(
      &Acknowledgement::entry_time,
      NDO_DATA_TIMESTAMP,
      "entry_time"),
    MappedData<Acknowledgement>(
      &Acknowledgement::host_name,
      NDO_DATA_HOSTNAME,
      "host_name"),
    MappedData<Acknowledgement>(
      &Acknowledgement::instance, // wtf is it here for ?
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<Acknowledgement>(
      &Acknowledgement::instance_name,
      NDO_DATA_PROGRAMNAME,
      "instance_name"),
    MappedData<Acknowledgement>(
      &Acknowledgement::is_sticky,
      NDO_DATA_STICKY,
      "is_sticky"),
    MappedData<Acknowledgement>(
      &Acknowledgement::notify_contacts,
      NDO_DATA_NOTIFYCONTACTS,
      "notify_contacts"),
    MappedData<Acknowledgement>(
      &Acknowledgement::persistent_comment,
      NDO_DATA_PERSISTENT,
      "persistent_comment"),
    MappedData<Acknowledgement>(
      &Acknowledgement::service_description,
      NDO_DATA_SERVICEDESCRIPTION,
      "service_description"),
    MappedData<Acknowledgement>(
      &Acknowledgement::state,
      NDO_DATA_STATE,
      "state"),
    MappedData<Acknowledgement>( // XXX : wtf is it here for ?
      &Acknowledgement::type,
      NDO_DATA_TYPE,
      NULL),
    MappedData<Acknowledgement>()
  };

// Comment members mapping.
static const MappedData<Comment> comment_mapping[] =
  {
    MappedData<Comment>(
      &Comment::author,
      NDO_DATA_AUTHORNAME,
      "author_name"),
    MappedData<Comment>(
      &Comment::comment,
      NDO_DATA_COMMENT,
      "comment_data"),
    MappedData<Comment>(
      &Comment::comment_time, // XXX : wtf is it here for ?
      0,
      "comment_time"),
    MappedData<Comment>(
      &Comment::comment_type,
      NDO_DATA_COMMENTTYPE,
      "comment_type"),
    MappedData<Comment>(
      &Comment::deletion_time, // XXX : wtf is it here for ?
      0,
      "deletion_time"),
    MappedData<Comment>(
      &Comment::entry_time,
      NDO_DATA_ENTRYTIME,
      "entry_time"),
    MappedData<Comment>(
      &Comment::entry_type,
      NDO_DATA_ENTRYTYPE,
      "entry_type"),
    MappedData<Comment>(
      &Comment::expire_time,
      NDO_DATA_EXPIRATIONTIME,
      "expire_time"),
    MappedData<Comment>(
      &Comment::expires,
      NDO_DATA_EXPIRES,
      "expires"),
    MappedData<Comment>(
      &Comment::host_name,
      NDO_DATA_HOSTNAME,
      "host_name"),
    MappedData<Comment>(
      &Comment::instance, // wtf is it here for ?
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<Comment>(
      &Comment::instance_name,
      NDO_DATA_PROGRAMNAME,
      "instance_name"),
    MappedData<Comment>(
      &Comment::internal_id,
      NDO_DATA_COMMENTID,
      "internal_id"),
    MappedData<Comment>(
      &Comment::persistent,
      NDO_DATA_PERSISTENT,
      "persistent"),
    MappedData<Comment>(
      &Comment::service_description,
      NDO_DATA_SERVICEDESCRIPTION,
      "service_description"),
    MappedData<Comment>(
      &Comment::source,
      NDO_DATA_SOURCE,
      "source"),
    MappedData<Comment>()
  };

// Downtime members mapping.
static const MappedData<Downtime> downtime_mapping[] =
  {
    MappedData<Downtime>(
      &Downtime::author,
      NDO_DATA_AUTHORNAME,
      "author_name"),
    MappedData<Downtime>(
      &Downtime::comment,
      NDO_DATA_COMMENT,
      "comment_data"),
    MappedData<Downtime>(
      &Downtime::downtime_type,
      NDO_DATA_DOWNTIMETYPE,
      "downtime_type"),
    MappedData<Downtime>(
      &Downtime::duration,
      NDO_DATA_DURATION,
      "duration"),
    MappedData<Downtime>(
      &Downtime::end_time,
      NDO_DATA_ENDTIME,
      "end_time"),
    MappedData<Downtime>(
      &Downtime::entry_time,
      NDO_DATA_ENTRYTIME,
      "entry_time"),
    MappedData<Downtime>(
      &Downtime::fixed,
      NDO_DATA_FIXED,
      "fixed"),
    MappedData<Downtime>(
      &Downtime::host_name,
      NDO_DATA_HOSTNAME,
      "host_name"),
    MappedData<Downtime>(
      &Downtime::id,
      NDO_DATA_DOWNTIMEID,
      "downtime_id"),
    MappedData<Downtime>(
      &Downtime::instance, // wtf is it here for ?
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<Downtime>(
      &Downtime::instance_name,
      NDO_DATA_PROGRAMNAME,
      "instance_name"),
    MappedData<Downtime>(
      &Downtime::service_description,
      NDO_DATA_SERVICEDESCRIPTION,
      "service_description"),
    MappedData<Downtime>(
      &Downtime::start_time,
      NDO_DATA_STARTTIME,
      "start_time"),
    MappedData<Downtime>(
      &Downtime::triggered_by,
      NDO_DATA_TRIGGEREDBY,
      "triggered_by"),
    MappedData<Downtime>( // XXX : wtf is it here for ?
      &Downtime::type,
      NDO_DATA_TYPE,
      NULL),
    MappedData<Downtime>(
      &Downtime::was_cancelled, // XXX : wtf is it here for ?
      0,
      "was_cancelled"),
    MappedData<Downtime>(
      &Downtime::was_started, // XXX : wtf is it here for ?
      0,
      "was_started"),
    MappedData<Downtime>()
  };

// Host members mapping.
static const MappedData<Host> host_mapping[] =
  {
    MappedData<Host>(
      &Host::acknowledgement_type,
      NDO_DATA_ACKNOWLEDGEMENTTYPE,
      "acknowledgement_type"),
    MappedData<Host>(
      &Host::action_url,
      NDO_DATA_ACTIONURL,
      "action_url"),
    MappedData<Host>(
      &Host::active_checks_enabled,
      NDO_DATA_ACTIVEHOSTCHECKSENABLED,
      "active_checks_enabled"),
    MappedData<Host>(
      &Host::address,
      NDO_DATA_HOSTADDRESS,
      "address"),
    MappedData<Host>(
      &Host::alias,
      NDO_DATA_HOSTALIAS,
      "alias"),
    MappedData<Host>(
      &Host::check_command,
      NDO_DATA_CHECKCOMMAND,
      "check_command"),
    MappedData<Host>(
      &Host::check_freshness,
      NDO_DATA_HOSTFRESHNESSCHECKSENABLED,
      "check_freshness"),
    MappedData<Host>(
      &Host::check_interval,
      NDO_DATA_NORMALCHECKINTERVAL,
      "check_interval"),
    MappedData<Host>(
      &Host::check_period,
      NDO_DATA_HOSTCHECKPERIOD,
      "check_period"),
    MappedData<Host>(
      &Host::check_type,
      NDO_DATA_CHECKTYPE,
      "check_type"),
    MappedData<Host>(
      &Host::current_check_attempt,
      NDO_DATA_CURRENTCHECKATTEMPT,
      "current_check_attempt"),
    MappedData<Host>(
      &Host::current_notification_number,
      NDO_DATA_CURRENTNOTIFICATIONNUMBER,
      "current_notification_number"),
    MappedData<Host>(
      &Host::current_state,
      NDO_DATA_CURRENTSTATE,
      "current_state"),
    MappedData<Host>(
      &Host::display_name,
      NDO_DATA_DISPLAYNAME,
      "display_name"),
    MappedData<Host>(
      &Host::event_handler,
      NDO_DATA_EVENTHANDLER,
      "event_handler"),
    MappedData<Host>(
      &Host::event_handler_enabled,
      NDO_DATA_EVENTHANDLERENABLED,
      "event_handler_enabled"),
    MappedData<Host>(
      &Host::execution_time,
      NDO_DATA_EXECUTIONTIME,
      "execution_time"),
    MappedData<Host>(
      &Host::failure_prediction_enabled,
      NDO_DATA_FAILUREPREDICTIONENABLED,
      "failure_prediction_enabled"),
    MappedData<Host>(
      &Host::first_notification_delay,
      NDO_DATA_FIRSTNOTIFICATIONDELAY,
      "first_notification_delay"),
    MappedData<Host>(
      &Host::flap_detection_enabled,
      NDO_DATA_FLAPDETECTIONENABLED,
      "flap_detection_enabled"),
    MappedData<Host>(
      &Host::flap_detection_on_down,
      NDO_DATA_FLAPDETECTIONONDOWN,
      "flap_detection_on_down"),
    MappedData<Host>(
      &Host::flap_detection_on_unreachable,
      NDO_DATA_FLAPDETECTIONONUNREACHABLE,
      "flap_detection_on_unreachable"),
    MappedData<Host>(
      &Host::flap_detection_on_up,
      NDO_DATA_FLAPDETECTIONONUP,
      "flap_detection_on_up"),
    MappedData<Host>(
      &Host::freshness_threshold,
      NDO_DATA_HOSTFRESHNESSTHRESHOLD,
      "freshness_threshold"),
    MappedData<Host>(
      &Host::has_been_checked,
      NDO_DATA_HASBEENCHECKED,
      "has_been_checked"),
    MappedData<Host>(
      &Host::have_2d_coords,
      NDO_DATA_HAVE2DCOORDS,
      "have_2d_coords"),
    MappedData<Host>(
      &Host::high_flap_threshold,
      NDO_DATA_HIGHHOSTFLAPTHRESHOLD,
      "high_flap_threshold"),
    MappedData<Host>(
      &Host::host,
      NDO_DATA_HOSTNAME,
      "host_name"),
    MappedData<Host>(
      &Host::icon_image,
      NDO_DATA_ICONIMAGE,
      "icon_image"),
    MappedData<Host>(
      &Host::icon_image_alt,
      NDO_DATA_ICONIMAGEALT,
      "icon_image_alt"),
    MappedData<Host>(
      &Host::id,
      NDO_DATA_HOST,
      "host_id"),
    MappedData<Host>(
      &Host::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<Host>(
      &Host::is_flapping,
      NDO_DATA_ISFLAPPING,
      "is_flapping"),
    MappedData<Host>(
      &Host::last_check,
      NDO_DATA_LASTHOSTCHECK,
      "last_check"),
    MappedData<Host>(
      &Host::last_hard_state,
      NDO_DATA_LASTHARDSTATE,
      "last_hard_state"),
    MappedData<Host>(
      &Host::last_hard_state_change,
      NDO_DATA_LASTHARDSTATECHANGE,
      "last_hard_state_change"),
    MappedData<Host>(
      &Host::last_notification,
      NDO_DATA_LASTHOSTNOTIFICATION,
      "last_notification"),
    MappedData<Host>(
      &Host::last_state_change,
      NDO_DATA_LASTSTATECHANGE,
      "last_state_change"),
    MappedData<Host>(
      &Host::last_time_down,
      NDO_DATA_LASTTIMEDOWN,
      "last_time_down"),
    MappedData<Host>(
      &Host::last_time_unreachable,
      NDO_DATA_LASTTIMEUNREACHABLE,
      "last_time_unreachable"),
    MappedData<Host>(
      &Host::last_time_up,
      NDO_DATA_LASTTIMEUP,
      "last_time_up"),
    MappedData<Host>(
      &Host::last_update,
      0, // XXX : should find macro
      "last_update"),
    MappedData<Host>(
      &Host::latency,
      NDO_DATA_LATENCY,
      "latency"),
    MappedData<Host>(
      &Host::long_output,
      NDO_DATA_LONGOUTPUT,
      "long_output"),
    MappedData<Host>(
      &Host::low_flap_threshold,
      NDO_DATA_LOWHOSTFLAPTHRESHOLD,
      "low_flap_threshold"),
    MappedData<Host>(
      &Host::max_check_attempts,
      NDO_DATA_MAXCHECKATTEMPTS,
      "max_check_attempts"),
    MappedData<Host>(
      &Host::modified_attributes,
      NDO_DATA_MODIFIEDHOSTATTRIBUTES,
      "modified_attributes"),
    MappedData<Host>(
      &Host::next_check,
      NDO_DATA_NEXTHOSTCHECK,
      "next_check"),
    MappedData<Host>(
      &Host::next_notification,
      NDO_DATA_NEXTHOSTNOTIFICATION,
      "next_host_notification"),
    MappedData<Host>(
      &Host::no_more_notifications,
      NDO_DATA_NOMORENOTIFICATIONS,
      "no_more_notifications"),
    MappedData<Host>(
      &Host::notes,
      NDO_DATA_NOTES,
      "notes"),
    MappedData<Host>(
      &Host::notes_url,
      NDO_DATA_NOTESURL,
      "notes_url"),
    MappedData<Host>(
      &Host::notification_interval,
      NDO_DATA_HOSTNOTIFICATIONINTERVAL,
      "notification_interval"),
    MappedData<Host>(
      &Host::notification_period,
      NDO_DATA_HOSTNOTIFICATIONPERIOD,
      "notification_period"),
    MappedData<Host>(
      &Host::notifications_enabled,
      NDO_DATA_NOTIFICATIONSENABLED,
      "notifications_enabled"),
    MappedData<Host>(
      &Host::notify_on_down,
      NDO_DATA_NOTIFYHOSTDOWN,
      "notify_on_down"),
    MappedData<Host>(
      &Host::notify_on_downtime,
      NDO_DATA_NOTIFYHOSTDOWNTIME,
      "notify_on_downtime"),
    MappedData<Host>(
      &Host::notify_on_flapping,
      NDO_DATA_NOTIFYHOSTFLAPPING,
      "notify_on_flapping"),
    MappedData<Host>(
      &Host::notify_on_recovery,
      NDO_DATA_NOTIFYHOSTRECOVERY,
      "notify_on_recovery"),
    MappedData<Host>(
      &Host::notify_on_unreachable,
      NDO_DATA_NOTIFYHOSTUNREACHABLE,
      "notify_on_unreachable"),
    MappedData<Host>(
      &Host::obsess_over,
      NDO_DATA_OBSESSOVERHOST,
      "obsess_over_host"),
    MappedData<Host>(
      &Host::output,
      NDO_DATA_OUTPUT,
      "output"),
    MappedData<Host>(
      &Host::passive_checks_enabled,
      NDO_DATA_PASSIVEHOSTCHECKSENABLED,
      "passive_checks_enabled"),
    MappedData<Host>(
      &Host::percent_state_change,
      NDO_DATA_PERCENTSTATECHANGE,
      "percent_state_change"),
    MappedData<Host>(
      &Host::perf_data,
      NDO_DATA_PERFDATA,
      "perf_data"),
    MappedData<Host>(
      &Host::problem_has_been_acknowledged,
      NDO_DATA_PROBLEMHASBEENACKNOWLEDGED,
      "problem_has_been_acknowledged"),
    MappedData<Host>(
      &Host::process_performance_data,
      NDO_DATA_PROCESSPERFORMANCEDATA,
      "process_performance_data"),
    MappedData<Host>(
      &Host::retain_nonstatus_information,
      NDO_DATA_RETAINHOSTNONSTATUSINFORMATION,
      "retain_nonstatus_information"),
    MappedData<Host>(
      &Host::retain_status_information,
      NDO_DATA_RETAINHOSTSTATUSINFORMATION,
      "retain_status_information"),
    MappedData<Host>(
      &Host::retry_interval,
      NDO_DATA_RETRYCHECKINTERVAL,
      "retry_interval"),
    MappedData<Host>(
      &Host::scheduled_downtime_depth,
      NDO_DATA_SCHEDULEDDOWNTIMEDEPTH,
      "scheduled_downtime_depth"),
    MappedData<Host>(
      &Host::should_be_scheduled,
      NDO_DATA_SHOULDBESCHEDULED,
      "should_be_scheduled"),
    MappedData<Host>(
      &Host::stalk_on_down,
      NDO_DATA_STALKHOSTONDOWN,
      "stalk_on_down"),
    MappedData<Host>(
      &Host::stalk_on_unreachable,
      NDO_DATA_STALKHOSTONUNREACHABLE,
      "stalk_on_unreachable"),
    MappedData<Host>(
      &Host::stalk_on_up,
      NDO_DATA_STALKHOSTONUP,
      "stalk_on_up"),
    MappedData<Host>(
      &Host::state_type,
      NDO_DATA_STATETYPE,
      "state_type"),
    MappedData<Host>(
      &Host::statusmap_image,
      NDO_DATA_STATUSMAPIMAGE,
      "statusmap_image"),
    MappedData<Host>(
      &Host::vrml_image,
      NDO_DATA_VRMLIMAGE,
      "vrml_image"),
    MappedData<Host>(
      &Host::x_2d,
      NDO_DATA_X2D,
      "x_2d"),
    MappedData<Host>(
      &Host::y_2d,
      NDO_DATA_Y2D,
      "y_2d"),
    MappedData<Host>()
  };

// HostCheck members mapping.
static const MappedData<HostCheck> host_check_mapping[] =
  {
    MappedData<HostCheck>(
      &HostCheck::command_line,
      NDO_DATA_COMMANDLINE,
      "command_line"),
    MappedData<HostCheck>(
      &HostCheck::id,
      NDO_DATA_HOST,
      "host_id"),
    MappedData<HostCheck>( // XXX : wtf is it here for ?
      &HostCheck::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<HostCheck>()
  };

// HostDependency members mapping.
static const MappedData<HostDependency> host_dependency_mapping[] =
  {
    MappedData<HostDependency>(
      &HostDependency::dependency_period,
      NDO_DATA_DEPENDENCYPERIOD,
      "dependency_period"),
    MappedData<HostDependency>(
      &HostDependency::dependent_object,
      NDO_DATA_DEPENDENTHOSTNAME, // XXX : bad macro name
      "dependent_host"),
    MappedData<HostDependency>(
      &HostDependency::inherits_parent,
      NDO_DATA_INHERITSPARENT,
      "inherits_parent"),
    MappedData<HostDependency>( // XXX : wtf is it here for ?
      &HostDependency::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<HostDependency>(
      &HostDependency::object,
      NDO_DATA_HOST,
      "host"),
    // XXX : where is execution_failure_options ?
    // XXX : where is notification_failure_options ?
    MappedData<HostDependency>()
  };

// HostGroup members mapping.
static const MappedData<HostGroup> host_group_mapping[] =
  {
    MappedData<HostGroup>(
      &HostGroup::action_url,
      NDO_DATA_ACTIONURL,
      "action_url"),
    MappedData<HostGroup>(
      &HostGroup::alias,
      NDO_DATA_HOSTGROUPALIAS,
      "alias"),
    MappedData<HostGroup>(
      &HostGroup::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<HostGroup>(
      &HostGroup::name,
      NDO_DATA_HOSTGROUPNAME,
      "hostgroup_name"),
    MappedData<HostGroup>(
      &HostGroup::notes,
      NDO_DATA_NOTES,
      "notes"),
    MappedData<HostGroup>(
      &HostGroup::notes_url,
      NDO_DATA_NOTESURL,
      "notes_url"),
    MappedData<HostGroup>()
  };

// HostGroupMember members mapping.
static const MappedData<HostGroupMember> host_group_member_mapping[] =
  {
    MappedData<HostGroupMember>(
      &HostGroupMember::group, // XXX : should be replaced by hostgroup_id
      NDO_DATA_HOSTGROUPNAME,
      NULL),
    MappedData<HostGroupMember>( // XXX : wtf is it here for ?
      &HostGroupMember::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<HostGroupMember>(
      &HostGroupMember::member,
      NDO_DATA_HOSTGROUPMEMBER,
      "host"),
    MappedData<HostGroupMember>()
  };

// HostParent members mapping.
static const MappedData<HostParent> host_parent_mapping[] =
  {
    MappedData<HostParent>(
      &HostParent::host,
      NDO_DATA_HOST,
      "host"),
    MappedData<HostParent>( // XXX : wtf is it here for ?
      &HostParent::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<HostParent>(
      &HostParent::parent,
      NDO_DATA_PARENTHOST,
      "parents"),
    MappedData<HostParent>()
  };

// HostStatus members mapping.
static const MappedData<HostStatus> host_status_mapping[] =
  {
    MappedData<HostStatus>(
      &HostStatus::acknowledgement_type,
      NDO_DATA_ACKNOWLEDGEMENTTYPE,
      "acknowledgement_type"),
    MappedData<HostStatus>(
      &HostStatus::active_checks_enabled,
      NDO_DATA_ACTIVEHOSTCHECKSENABLED,
      "active_checks_enabled"),
    MappedData<HostStatus>(
      &HostStatus::check_command,
      NDO_DATA_CHECKCOMMAND,
      "check_command"),
    MappedData<HostStatus>(
      &HostStatus::check_interval,
      NDO_DATA_NORMALCHECKINTERVAL,
      "check_interval"),
    MappedData<HostStatus>(
      &HostStatus::check_period,
      NDO_DATA_HOSTCHECKPERIOD,
      "check_period"),
    MappedData<HostStatus>(
      &HostStatus::check_type,
      NDO_DATA_CHECKTYPE,
      "check_type"),
    MappedData<HostStatus>(
      &HostStatus::current_check_attempt,
      NDO_DATA_CURRENTCHECKATTEMPT,
      "current_check_attempt"),
    MappedData<HostStatus>(
      &HostStatus::current_notification_number,
      NDO_DATA_CURRENTNOTIFICATIONNUMBER,
      "current_notification_number"),
    MappedData<HostStatus>(
      &HostStatus::current_state,
      NDO_DATA_CURRENTSTATE,
      "current_state"),
    MappedData<HostStatus>(
      &HostStatus::event_handler,
      NDO_DATA_EVENTHANDLER,
      "event_handler"),
    MappedData<HostStatus>(
      &HostStatus::event_handler_enabled,
      NDO_DATA_EVENTHANDLERENABLED,
      "event_handler_enabled"),
    MappedData<HostStatus>(
      &HostStatus::execution_time,
      NDO_DATA_EXECUTIONTIME,
      "execution_time"),
    MappedData<HostStatus>(
      &HostStatus::failure_prediction_enabled,
      NDO_DATA_FAILUREPREDICTIONENABLED,
      "failure_prediction_enabled"),
    MappedData<HostStatus>(
      &HostStatus::flap_detection_enabled,
      NDO_DATA_FLAPDETECTIONENABLED,
      "flap_detection_enabled"),
    MappedData<HostStatus>(
      &HostStatus::has_been_checked,
      NDO_DATA_HASBEENCHECKED,
      "has_been_checked"),
    MappedData<HostStatus>(
      &HostStatus::id,
      NDO_DATA_HOST,
      "host_id"),
    MappedData<HostStatus>(
      &HostStatus::instance, // XXX : should be replaced by instance_id
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<HostStatus>(
      &HostStatus::is_flapping,
      NDO_DATA_ISFLAPPING,
      "is_flapping"),
    MappedData<HostStatus>(
      &HostStatus::last_check,
      NDO_DATA_LASTHOSTCHECK,
      "last_check"),
    MappedData<HostStatus>(
      &HostStatus::last_hard_state,
      NDO_DATA_LASTHARDSTATE,
      "last_hard_state"),
    MappedData<HostStatus>(
      &HostStatus::last_hard_state_change,
      NDO_DATA_LASTHARDSTATECHANGE,
      "last_hard_state_change"),
    MappedData<HostStatus>(
      &HostStatus::last_notification,
      NDO_DATA_LASTHOSTNOTIFICATION,
      "last_notification"),
    MappedData<HostStatus>(
      &HostStatus::last_state_change,
      NDO_DATA_LASTSTATECHANGE,
      "last_state_change"),
    MappedData<HostStatus>(
      &HostStatus::last_time_down,
      NDO_DATA_LASTTIMEDOWN,
      "last_time_down"),
    MappedData<HostStatus>(
      &HostStatus::last_time_unreachable,
      NDO_DATA_LASTTIMEUNREACHABLE,
      "last_time_unreachable"),
    MappedData<HostStatus>(
      &HostStatus::last_time_up,
      NDO_DATA_LASTTIMEUP,
      "last_time_up"),
    MappedData<HostStatus>(
      &HostStatus::last_update,
      0, // XXX : should find macro
      "last_update"),
    MappedData<HostStatus>(
      &HostStatus::latency,
      NDO_DATA_LATENCY,
      "latency"),
    MappedData<HostStatus>(
      &HostStatus::long_output,
      NDO_DATA_LONGOUTPUT,
      "long_output"),
    MappedData<HostStatus>(
      &HostStatus::max_check_attempts,
      NDO_DATA_MAXCHECKATTEMPTS,
      "max_check_attempts"),
    MappedData<HostStatus>(
      &HostStatus::modified_attributes,
      NDO_DATA_MODIFIEDHOSTATTRIBUTES,
      "modified_attributes"),
    MappedData<HostStatus>(
      &HostStatus::next_check,
      NDO_DATA_NEXTHOSTCHECK,
      "next_check"),
    MappedData<HostStatus>(
      &HostStatus::next_notification,
      NDO_DATA_NEXTHOSTNOTIFICATION,
      "next_host_notification"),
    MappedData<HostStatus>(
      &HostStatus::no_more_notifications,
      NDO_DATA_NOMORENOTIFICATIONS,
      "no_more_notifications"),
    MappedData<HostStatus>(
      &HostStatus::notifications_enabled,
      NDO_DATA_NOTIFICATIONSENABLED,
      "notifications_enabled"),
    MappedData<HostStatus>(
      &HostStatus::obsess_over,
      NDO_DATA_OBSESSOVERHOST,
      "obsess_over_host"),
    MappedData<HostStatus>(
      &HostStatus::output,
      NDO_DATA_OUTPUT,
      "output"),
    MappedData<HostStatus>(
      &HostStatus::passive_checks_enabled,
      NDO_DATA_PASSIVEHOSTCHECKSENABLED,
      "passive_checks_enabled"),
    MappedData<HostStatus>(
      &HostStatus::percent_state_change,
      NDO_DATA_PERCENTSTATECHANGE,
      "percent_state_change"),
    MappedData<HostStatus>(
      &HostStatus::perf_data,
      NDO_DATA_PERFDATA,
      "perf_data"),
    MappedData<HostStatus>(
      &HostStatus::problem_has_been_acknowledged,
      NDO_DATA_PROBLEMHASBEENACKNOWLEDGED,
      "problem_has_been_acknowledged"),
    MappedData<HostStatus>(
      &HostStatus::process_performance_data,
      NDO_DATA_PROCESSPERFORMANCEDATA,
      "process_performance_data"),
    MappedData<HostStatus>(
      &HostStatus::retry_interval,
      NDO_DATA_RETRYCHECKINTERVAL,
      "retry_interval"),
    MappedData<HostStatus>(
      &HostStatus::scheduled_downtime_depth,
      NDO_DATA_SCHEDULEDDOWNTIMEDEPTH,
      "scheduled_downtime_depth"),
    MappedData<HostStatus>(
      &HostStatus::should_be_scheduled,
      NDO_DATA_SHOULDBESCHEDULED,
      "should_be_scheduled"),
    MappedData<HostStatus>(
      &HostStatus::state_type,
      NDO_DATA_STATETYPE,
      "state_type"),
    MappedData<HostStatus>()
  };

// Log members mapping.
static const MappedData<Log> log_mapping[] =
  {
    MappedData<Log>(
      &Log::c_time,
      NDO_DATA_LOGENTRYTIME,
      "ctime"),
    MappedData<Log>(
      &Log::host, // XXX : should be replaced by host_id
      NDO_DATA_HOST,
      "host_name"),
    MappedData<Log>(
      &Log::instance,
      NDO_DATA_INSTANCE,
      "instance"),
    MappedData<Log>(
      &Log::msg_type,
      NDO_DATA_ENTRYTYPE,
      "msg_type"),
    MappedData<Log>(
      &Log::notification_cmd,
      NDO_DATA_HOSTNOTIFICATIONCOMMAND,
      "notification_cmd"),
    MappedData<Log>(
      &Log::notification_contact,
      NDO_DATA_CONTACT,
      "notification_contact"),
    MappedData<Log>(
      &Log::output,
      NDO_DATA_OUTPUT,
      "output"),
    MappedData<Log>(
      &Log::retry,
      NDO_DATA_HOSTRETRYINTERVAL,
      "retry"),
    MappedData<Log>(
      &Log::service, // XXX : should be replaced by service_id
      NDO_DATA_SERVICE,
      "service_description"),
    MappedData<Log>(
      &Log::status,
      NDO_DATA_CURRENTSTATE,
      "status"),
    MappedData<Log>(
      &Log::type,
      NDO_DATA_TYPE,
      "type"),
    MappedData<Log>()
  };

// Program members mapping.
static const MappedData<Program> program_mapping[] =
  {
    MappedData<Program>(
      &Program::daemon_mode,
      NDO_DATA_DAEMONMODE,
      "daemon_mode"),
    MappedData<Program>(
      &Program::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<Program>(
      &Program::instance_name,
      NDO_DATA_PROGRAMNAME,
      "instance_name"),
    MappedData<Program>(
      &Program::is_running,
      NDO_DATA_RUNTIME,
      "is_running"),
    MappedData<Program>(
      &Program::pid,
      NDO_DATA_PROCESSID,
      "pid"),
    MappedData<Program>(
      &Program::program_end,
      NDO_DATA_ENDTIME,
      "program_end"),
    MappedData<Program>(
      &Program::program_start,
      NDO_DATA_PROGRAMSTARTTIME,
      "program_start"),
    MappedData<Program>()
  };

// ProgramStatus members mapping.
static const MappedData<ProgramStatus> program_status_mapping[] =
  {
    MappedData<ProgramStatus>(
      &ProgramStatus::active_host_checks_enabled,
      NDO_DATA_ACTIVEHOSTCHECKSENABLED,
      "active_host_checks_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::active_service_checks_enabled,
      NDO_DATA_ACTIVESERVICECHECKSENABLED,
      "active_service_checks_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::event_handler_enabled,
      NDO_DATA_EVENTHANDLERENABLED,
      "event_handlers_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::failure_prediction_enabled,
      NDO_DATA_FAILUREPREDICTIONENABLED,
      "failure_prediction_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::flap_detection_enabled,
      NDO_DATA_FLAPDETECTIONENABLED,
      "flap_detection_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::global_host_event_handler,
      NDO_DATA_GLOBALHOSTEVENTHANDLER,
      "global_host_event_handler"),
    MappedData<ProgramStatus>(
      &ProgramStatus::global_service_event_handler,
      NDO_DATA_GLOBALSERVICEEVENTHANDLER,
      "global_service_event_handler"),
    MappedData<ProgramStatus>(
      &ProgramStatus::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<ProgramStatus>(
      &ProgramStatus::last_alive,
      0, // XXX : should find macro
      "last_alive"),
    MappedData<ProgramStatus>(
      &ProgramStatus::last_command_check,
      NDO_DATA_LASTCOMMANDCHECK,
      "last_command_check"),
    MappedData<ProgramStatus>(
      &ProgramStatus::last_log_rotation,
      NDO_DATA_LASTLOGROTATION,
      "last_log_rotation"),
    MappedData<ProgramStatus>(
      &ProgramStatus::modified_host_attributes,
      NDO_DATA_MODIFIEDHOSTATTRIBUTES,
      "modified_host_attributes"),
    MappedData<ProgramStatus>(
      &ProgramStatus::modified_service_attributes,
      NDO_DATA_MODIFIEDSERVICEATTRIBUTES,
      "modified_service_attributes"),
    MappedData<ProgramStatus>(
      &ProgramStatus::notifications_enabled,
      NDO_DATA_NOTIFICATIONSENABLED,
      "notifications_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::obsess_over_hosts,
      NDO_DATA_OBSESSOVERHOST,
      "obsess_over_hosts"),
    MappedData<ProgramStatus>(
      &ProgramStatus::obsess_over_services,
      NDO_DATA_OBSESSOVERSERVICE,
      "obsess_over_services"),
    MappedData<ProgramStatus>(
      &ProgramStatus::passive_host_checks_enabled,
      NDO_DATA_PASSIVEHOSTCHECKSENABLED,
      "passive_host_checks_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::passive_service_checks_enabled,
      NDO_DATA_PASSIVESERVICECHECKSENABLED,
      "passive_service_checks_enabled"),
    MappedData<ProgramStatus>(
      &ProgramStatus::process_performance_data,
      NDO_DATA_PROCESSPERFORMANCEDATA,
      "process_performance_data"),
    // XXX : no instance_address
    // XXX : no instance_description
    MappedData<ProgramStatus>()
  };

// Service members mapping.
static const MappedData<Service> service_mapping[] =
  {
    MappedData<Service>(
      &Service::acknowledgement_type,
      NDO_DATA_ACKNOWLEDGEMENTTYPE,
      "acknowledgement_type"),
    MappedData<Service>(
      &Service::action_url,
      NDO_DATA_ACTIONURL,
      "action_url"),
    MappedData<Service>(
      &Service::active_checks_enabled,
      NDO_DATA_ACTIVESERVICECHECKSENABLED,
      "active_checks_enabled"),
    MappedData<Service>(
      &Service::check_command,
      NDO_DATA_CHECKCOMMAND,
      "check_command"),
    MappedData<Service>(
      &Service::check_freshness,
      NDO_DATA_SERVICEFRESHNESSCHECKSENABLED,
      "check_freshness"),
    MappedData<Service>(
      &Service::check_interval,
      NDO_DATA_NORMALCHECKINTERVAL,
      "check_interval"),
    MappedData<Service>(
      &Service::check_period,
      NDO_DATA_SERVICECHECKPERIOD,
      "check_period"),
    MappedData<Service>(
      &Service::check_type,
      NDO_DATA_CHECKTYPE,
      "check_type"),
    MappedData<Service>(
      &Service::current_check_attempt,
      NDO_DATA_CURRENTCHECKATTEMPT,
      "current_attempt"),
    MappedData<Service>(
      &Service::current_notification_number,
      NDO_DATA_CURRENTNOTIFICATIONNUMBER,
      "current_notification_number"),
    MappedData<Service>(
      &Service::current_state,
      NDO_DATA_CURRENTSTATE,
      "current_state"),
    MappedData<Service>(
      &Service::display_name,
      NDO_DATA_DISPLAYNAME,
      "display_name"),
    MappedData<Service>(
      &Service::event_handler,
      NDO_DATA_EVENTHANDLER,
      "event_handler"),
    MappedData<Service>(
      &Service::event_handler_enabled,
      NDO_DATA_EVENTHANDLERENABLED,
      "event_handler_enabled"),
    MappedData<Service>(
      &Service::execution_time,
      NDO_DATA_EXECUTIONTIME,
      "execution_time"),
    MappedData<Service>(
      &Service::failure_prediction_enabled,
      NDO_DATA_FAILUREPREDICTIONENABLED,
      "failure_prediction_enabled"),
    MappedData<Service>(
      &Service::failure_prediction_options,
      NDO_DATA_SERVICEFAILUREPREDICTIONOPTIONS,
      "failure_prediction_options"),
    MappedData<Service>(
      &Service::first_notification_delay,
      NDO_DATA_FIRSTNOTIFICATIONDELAY,
      "first_notification_delay"),
    MappedData<Service>(
      &Service::flap_detection_enabled,
      NDO_DATA_FLAPDETECTIONENABLED,
      "flap_detection_enabled"),
    MappedData<Service>(
      &Service::flap_detection_on_critical,
      NDO_DATA_FLAPDETECTIONONCRITICAL,
      "flap_detection_on_critical"),
    MappedData<Service>(
      &Service::flap_detection_on_ok,
      NDO_DATA_FLAPDETECTIONONOK,
      "flap_detection_on_ok"),
    MappedData<Service>(
      &Service::flap_detection_on_unknown,
      NDO_DATA_FLAPDETECTIONONUNKNOWN,
      "flap_detection_on_unknown"),
    MappedData<Service>(
      &Service::flap_detection_on_warning,
      NDO_DATA_FLAPDETECTIONONWARNING,
      "flap_detection_on_warning"),
    MappedData<Service>(
      &Service::freshness_threshold,
      NDO_DATA_SERVICEFRESHNESSTHRESHOLD,
      "freshness_threshold"),
    MappedData<Service>(
      &Service::has_been_checked,
      NDO_DATA_HASBEENCHECKED,
      "has_been_checked"),
    MappedData<Service>(
      &Service::high_flap_threshold,
      NDO_DATA_HIGHSERVICEFLAPTHRESHOLD,
      "high_flap_threshold"),
    MappedData<Service>(
      &Service::host,
      NDO_DATA_HOSTNAME,
      "host_name"),
    MappedData<Service>(
      &Service::host_id,
      NDO_DATA_HOST,
      "host_id"),
    MappedData<Service>(
      &Service::icon_image,
      NDO_DATA_ICONIMAGE,
      "icon_image"),
    MappedData<Service>(
      &Service::icon_image_alt,
      NDO_DATA_ICONIMAGEALT,
      "icon_image_alt"),
    MappedData<Service>(
      &Service::id,
      NDO_DATA_SERVICE,
      "service_id"),
    MappedData<Service>(
      &Service::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<Service>(
      &Service::is_flapping,
      NDO_DATA_ISFLAPPING,
      "is_flapping"),
    MappedData<Service>(
      &Service::is_volatile,
      NDO_DATA_SERVICEISVOLATILE,
      "is_volatile"),
    MappedData<Service>(
      &Service::last_check,
      NDO_DATA_LASTSERVICECHECK,
      "last_check"),
    MappedData<Service>(
      &Service::last_hard_state,
      NDO_DATA_LASTHARDSTATE,
      "last_hard_state"),
    MappedData<Service>(
      &Service::last_hard_state_change,
      NDO_DATA_LASTHARDSTATECHANGE,
      "last_hard_state_change"),
    MappedData<Service>(
      &Service::last_notification,
      NDO_DATA_LASTSERVICENOTIFICATION,
      "last_notification"),
    MappedData<Service>(
      &Service::last_state_change,
      NDO_DATA_LASTSTATECHANGE,
      "last_state_change"),
    MappedData<Service>(
      &Service::last_time_critical,
      NDO_DATA_LASTTIMECRITICAL,
      "last_time_critical"),
    MappedData<Service>(
      &Service::last_time_ok,
      NDO_DATA_LASTTIMEOK,
      "last_time_ok"),
    MappedData<Service>(
      &Service::last_time_unknown,
      NDO_DATA_LASTTIMEUNKNOWN,
      "last_time_unknown"),
    MappedData<Service>(
      &Service::last_time_warning,
      NDO_DATA_LASTTIMEWARNING,
      "last_time_warning"),
    MappedData<Service>(
      &Service::last_update,
      0, // XXX : should find macro
      "last_update"),
    MappedData<Service>(
      &Service::latency,
      NDO_DATA_LATENCY,
      "latency"),
    MappedData<Service>(
      &Service::long_output,
      NDO_DATA_LONGOUTPUT,
      "long_output"),
    MappedData<Service>(
      &Service::low_flap_threshold,
      NDO_DATA_LOWSERVICEFLAPTHRESHOLD,
      "low_flap_threshold"),
    MappedData<Service>(
      &Service::max_check_attempts,
      NDO_DATA_MAXCHECKATTEMPTS,
      "max_check_attempts"),
    MappedData<Service>(
      &Service::modified_attributes,
      NDO_DATA_MODIFIEDSERVICEATTRIBUTES,
      "modified_attributes"),
    MappedData<Service>(
      &Service::next_check,
      NDO_DATA_NEXTSERVICECHECK,
      "next_check"),
    MappedData<Service>(
      &Service::next_notification,
      NDO_DATA_NEXTSERVICENOTIFICATION,
      "next_notification"),
    MappedData<Service>(
      &Service::no_more_notifications,
      NDO_DATA_NOMORENOTIFICATIONS,
      "no_more_notifications"),
    MappedData<Service>(
      &Service::notes,
      NDO_DATA_NOTES,
      "notes"),
    MappedData<Service>(
      &Service::notes_url,
      NDO_DATA_NOTESURL,
      "notes_url"),
    MappedData<Service>(
      &Service::notification_interval,
      NDO_DATA_SERVICENOTIFICATIONINTERVAL,
      "notification_interval"),
    MappedData<Service>(
      &Service::notification_period,
      NDO_DATA_SERVICENOTIFICATIONPERIOD,
      "notification_period"),
    MappedData<Service>(
      &Service::notifications_enabled,
      NDO_DATA_NOTIFICATIONSENABLED,
      "notifications_enabled"),
    MappedData<Service>(
      &Service::notified_on_critical,
      NDO_DATA_NOTIFYSERVICECRITICAL,
      "notified_on_critical"),
    MappedData<Service>(
      &Service::notified_on_unknown,
      NDO_DATA_NOTIFYSERVICEUNKNOWN,
      "notified_on_unknown"),
    MappedData<Service>(
      &Service::notified_on_warning,
      NDO_DATA_NOTIFYSERVICEWARNING,
      "notified_on_warning"),
    MappedData<Service>(
      &Service::notify_on_downtime,
      NDO_DATA_NOTIFYSERVICEDOWNTIME,
      "notify_on_downtime"),
    MappedData<Service>(
      &Service::notify_on_flapping,
      NDO_DATA_NOTIFYSERVICEFLAPPING,
      "notify_on_flapping"),
    MappedData<Service>(
      &Service::notify_on_recovery,
      NDO_DATA_NOTIFYSERVICERECOVERY,
      "notify_on_recovery"),
    MappedData<Service>(
      &Service::obsess_over,
      NDO_DATA_OBSESSOVERSERVICE,
      "obsess_over_service"),
    MappedData<Service>(
      &Service::output,
      NDO_DATA_OUTPUT,
      "output"),
    MappedData<Service>(
      &Service::passive_checks_enabled,
      NDO_DATA_PASSIVESERVICECHECKSENABLED,
      "passive_checks_enabled"),
    MappedData<Service>(
      &Service::percent_state_change,
      NDO_DATA_PERCENTSTATECHANGE,
      "percent_state_change"),
    MappedData<Service>(
      &Service::perf_data,
      NDO_DATA_PERFDATA,
      "perf_data"),
    MappedData<Service>(
      &Service::problem_has_been_acknowledged,
      NDO_DATA_PROBLEMHASBEENACKNOWLEDGED,
      "problem_has_been_acknowledged"),
    MappedData<Service>(
      &Service::process_performance_data,
      NDO_DATA_PROCESSPERFORMANCEDATA,
      "process_performance_data"),
    MappedData<Service>(
      &Service::retain_nonstatus_information,
      NDO_DATA_RETAINSERVICENONSTATUSINFORMATION,
      "retain_nonstatus_information"),
    MappedData<Service>(
      &Service::retain_status_information,
      NDO_DATA_RETAINSERVICESTATUSINFORMATION,
      "retain_status_information"),
    MappedData<Service>(
      &Service::retry_interval,
      NDO_DATA_RETRYCHECKINTERVAL,
      "retry_interval"),
    MappedData<Service>(
      &Service::scheduled_downtime_depth,
      NDO_DATA_SCHEDULEDDOWNTIMEDEPTH,
      "scheduled_downtime_depth"),
    MappedData<Service>(
      &Service::service,
      NDO_DATA_SERVICEDESCRIPTION,
      "service_description"),
    MappedData<Service>(
      &Service::should_be_scheduled,
      NDO_DATA_SHOULDBESCHEDULED,
      "should_be_scheduled"),
    MappedData<Service>(
      &Service::stalk_on_critical,
      NDO_DATA_STALKSERVICEONCRITICAL,
      "stalk_on_critical"),
    MappedData<Service>(
      &Service::stalk_on_ok,
      NDO_DATA_STALKSERVICEONOK,
      "stalk_on_ok"),
    MappedData<Service>(
      &Service::stalk_on_unknown,
      NDO_DATA_STALKSERVICEONUNKNOWN,
      "stalk_on_unknown"),
    MappedData<Service>(
      &Service::stalk_on_warning,
      NDO_DATA_STALKSERVICEONWARNING,
      "stalk_on_warning"),
    MappedData<Service>(
      &Service::state_type,
      NDO_DATA_STATETYPE,
      "state_type"),
    MappedData<Service>()
  };

// ServiceCheck members mapping.
static const MappedData<ServiceCheck> service_check_mapping[] =
  {
    MappedData<ServiceCheck>(
      &ServiceCheck::command_line,
      NDO_DATA_COMMANDLINE,
      "command_line"),
    MappedData<ServiceCheck>(
      &ServiceCheck::id,
      NDO_DATA_SERVICE,
      "service_id"),
    MappedData<ServiceCheck>( // XXX : wtf is it here for ?
      &ServiceCheck::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<ServiceCheck>()
  };

// ServiceDependency members mapping.
static const MappedData<ServiceDependency> service_dependency_mapping[] =
  {
    MappedData<ServiceDependency>(
      &ServiceDependency::dependency_period,
      NDO_DATA_DEPENDENCYPERIOD,
      "dependency_period"),
    MappedData<ServiceDependency>(
      &ServiceDependency::dependent_object,
      NDO_DATA_DEPENDENTSERVICEDESCRIPTION, // XXX : bad macro name
      "dependent_service"),
    MappedData<ServiceDependency>(
      &ServiceDependency::inherits_parent,
      NDO_DATA_INHERITSPARENT,
      "inherits_parent"),
    MappedData<ServiceDependency>( // XXX : wtf is it here for ?
      &ServiceDependency::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<ServiceDependency>(
      &ServiceDependency::object,
      NDO_DATA_SERVICE,
      "service"),
    // XXX : where is execution_failure_options ?
    // XXX : where is notification_failure_options ?
    MappedData<ServiceDependency>()
  };

// ServiceGroup members mapping.
static const MappedData<ServiceGroup> service_group_mapping[] =
  {
    MappedData<ServiceGroup>(
      &ServiceGroup::action_url,
      NDO_DATA_ACTIONURL,
      "action_url"),
    MappedData<ServiceGroup>(
      &ServiceGroup::alias,
      NDO_DATA_SERVICEGROUPALIAS,
      "alias"),
    MappedData<ServiceGroup>(
      &ServiceGroup::instance,
      NDO_DATA_INSTANCE,
      "instance_id"),
    MappedData<ServiceGroup>(
      &ServiceGroup::name,
      NDO_DATA_SERVICEGROUPNAME,
      "servicegroup_name"),
    MappedData<ServiceGroup>(
      &ServiceGroup::notes,
      NDO_DATA_NOTES,
      "notes"),
    MappedData<ServiceGroup>(
      &ServiceGroup::notes_url,
      NDO_DATA_NOTESURL,
      "notes_url"),
    MappedData<ServiceGroup>()
  };

// ServiceGroupMember members mapping.
static const MappedData<ServiceGroupMember> service_group_member_mapping[] =
  {
    MappedData<ServiceGroupMember>(
      &ServiceGroupMember::group, // XXX : should be replaced by servicegroup_id
      NDO_DATA_SERVICEGROUPNAME,
      NULL),
    MappedData<ServiceGroupMember>( // XXX : wtf is it here for ?
      &ServiceGroupMember::instance,
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<ServiceGroupMember>(
      &ServiceGroupMember::member,
      NDO_DATA_SERVICEGROUPMEMBER,
      "service"),
    MappedData<ServiceGroupMember>()
  };

// ServiceStatus members mapping.
static const MappedData<ServiceStatus> service_status_mapping[] =
  {
    MappedData<ServiceStatus>(
      &ServiceStatus::acknowledgement_type,
      NDO_DATA_ACKNOWLEDGEMENTTYPE,
      "acknowledgement_type"),
    MappedData<ServiceStatus>(
      &ServiceStatus::active_checks_enabled,
      NDO_DATA_ACTIVESERVICECHECKSENABLED,
      "active_checks_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::check_command,
      NDO_DATA_CHECKCOMMAND,
      "check_command"),
    MappedData<ServiceStatus>(
      &ServiceStatus::check_interval,
      NDO_DATA_NORMALCHECKINTERVAL,
      "check_interval"),
    MappedData<ServiceStatus>(
      &ServiceStatus::check_period,
      NDO_DATA_SERVICECHECKPERIOD,
      "check_period"),
    MappedData<ServiceStatus>(
      &ServiceStatus::check_type,
      NDO_DATA_CHECKTYPE,
      "check_type"),
    MappedData<ServiceStatus>(
      &ServiceStatus::current_check_attempt,
      NDO_DATA_CURRENTCHECKATTEMPT,
      "current_attempt"),
    MappedData<ServiceStatus>(
      &ServiceStatus::current_notification_number,
      NDO_DATA_CURRENTNOTIFICATIONNUMBER,
      "current_notification_number"),
    MappedData<ServiceStatus>(
      &ServiceStatus::current_state,
      NDO_DATA_CURRENTSTATE,
      "current_state"),
    MappedData<ServiceStatus>(
      &ServiceStatus::event_handler,
      NDO_DATA_EVENTHANDLER,
      "event_handler"),
    MappedData<ServiceStatus>(
      &ServiceStatus::event_handler_enabled,
      NDO_DATA_EVENTHANDLERENABLED,
      "event_handler_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::execution_time,
      NDO_DATA_EXECUTIONTIME,
      "execution_time"),
    MappedData<ServiceStatus>(
      &ServiceStatus::failure_prediction_enabled,
      NDO_DATA_FAILUREPREDICTIONENABLED,
      "failure_prediction_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::flap_detection_enabled,
      NDO_DATA_FLAPDETECTIONENABLED,
      "flap_detection_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::has_been_checked,
      NDO_DATA_HASBEENCHECKED,
      "has_been_checked"),
    MappedData<ServiceStatus>(
      &ServiceStatus::instance, // XXX : should be replaced by instance_id
      NDO_DATA_INSTANCE,
      NULL),
    MappedData<ServiceStatus>(
      &ServiceStatus::is_flapping,
      NDO_DATA_ISFLAPPING,
      "is_flapping"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_check,
      NDO_DATA_LASTSERVICECHECK,
      "last_check"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_hard_state,
      NDO_DATA_LASTHARDSTATE,
      "last_hard_state"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_hard_state_change,
      NDO_DATA_LASTHARDSTATECHANGE,
      "last_hard_state_change"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_notification,
      NDO_DATA_LASTSERVICENOTIFICATION,
      "last_notification"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_state_change,
      NDO_DATA_LASTSTATECHANGE,
      "last_state_change"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_time_critical,
      NDO_DATA_LASTTIMECRITICAL,
      "last_time_critical"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_time_ok,
      NDO_DATA_LASTTIMEOK,
      "last_time_ok"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_time_unknown,
      NDO_DATA_LASTTIMEUNKNOWN,
      "last_time_unknown"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_time_warning,
      NDO_DATA_LASTTIMEWARNING,
      "last_time_warning"),
    MappedData<ServiceStatus>(
      &ServiceStatus::last_update,
      0, // XXX : should find macro
      "last_update"),
    MappedData<ServiceStatus>(
      &ServiceStatus::latency,
      NDO_DATA_LATENCY,
      "latency"),
    MappedData<ServiceStatus>(
      &ServiceStatus::long_output,
      NDO_DATA_LONGOUTPUT,
      "long_output"),
    MappedData<ServiceStatus>(
      &ServiceStatus::max_check_attempts,
      NDO_DATA_MAXCHECKATTEMPTS,
      "max_check_attempts"),
    MappedData<ServiceStatus>(
      &ServiceStatus::modified_attributes,
      NDO_DATA_MODIFIEDSERVICEATTRIBUTES,
      "modified_attributes"),
    MappedData<ServiceStatus>(
      &ServiceStatus::next_check,
      NDO_DATA_NEXTSERVICECHECK,
      "next_check"),
    MappedData<ServiceStatus>(
      &ServiceStatus::next_notification,
      NDO_DATA_NEXTSERVICENOTIFICATION,
      "next_notification"),
    MappedData<ServiceStatus>(
      &ServiceStatus::no_more_notifications,
      NDO_DATA_NOMORENOTIFICATIONS,
      "no_more_notifications"),
    MappedData<ServiceStatus>(
      &ServiceStatus::notifications_enabled,
      NDO_DATA_NOTIFICATIONSENABLED,
      "notifications_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::obsess_over,
      NDO_DATA_OBSESSOVERSERVICE,
      "obsess_over_service"),
    MappedData<ServiceStatus>(
      &ServiceStatus::output,
      NDO_DATA_OUTPUT,
      "output"),
    MappedData<ServiceStatus>(
      &ServiceStatus::passive_checks_enabled,
      NDO_DATA_PASSIVESERVICECHECKSENABLED,
      "passive_checks_enabled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::percent_state_change,
      NDO_DATA_PERCENTSTATECHANGE,
      "percent_state_change"),
    MappedData<ServiceStatus>(
      &ServiceStatus::perf_data,
      NDO_DATA_PERFDATA,
      "perf_data"),
    MappedData<ServiceStatus>(
      &ServiceStatus::problem_has_been_acknowledged,
      NDO_DATA_PROBLEMHASBEENACKNOWLEDGED,
      "problem_has_been_acknowledged"),
    MappedData<ServiceStatus>(
      &ServiceStatus::process_performance_data,
      NDO_DATA_PROCESSPERFORMANCEDATA,
      "process_performance_data"),
    MappedData<ServiceStatus>(
      &ServiceStatus::retry_interval,
      NDO_DATA_RETRYCHECKINTERVAL,
      "retry_interval"),
    MappedData<ServiceStatus>(
      &ServiceStatus::scheduled_downtime_depth,
      NDO_DATA_SCHEDULEDDOWNTIMEDEPTH,
      "scheduled_downtime_depth"),
    MappedData<ServiceStatus>(
      &ServiceStatus::id,
      NDO_DATA_SERVICE,
      "service_id"),
    MappedData<ServiceStatus>(
      &ServiceStatus::should_be_scheduled,
      NDO_DATA_SHOULDBESCHEDULED,
      "should_be_scheduled"),
    MappedData<ServiceStatus>(
      &ServiceStatus::state_type,
      NDO_DATA_STATETYPE,
      "state_type"),
    MappedData<ServiceStatus>()
  };

// Acknowledgement mapping.
template <> const MappedData<Events::Acknowledgement>*
  MappedType<Events::Acknowledgement>::members(acknowledgement_mapping);
template <> const char*
  MappedType<Events::Acknowledgement>::table("acknowledgements");

// Comment mapping.
template <> const MappedData<Events::Comment>*
  MappedType<Events::Comment>::members(comment_mapping);
template <> const char*
  MappedType<Events::Comment>::table("comment");

// Downtime mapping.
template <> const MappedData<Events::Downtime>*
  MappedType<Events::Downtime>::members(downtime_mapping);
template <> const char*
  MappedType<Events::Downtime>::table("scheduled_downtime");

// Host mapping.
template <> const MappedData<Events::Host>*
  MappedType<Events::Host>::members(host_mapping);
template <> const char*
  MappedType<Events::Host>::table("host");

// HostCheck mapping.
template <> const MappedData<Events::HostCheck>*
  MappedType<Events::HostCheck>::members(host_check_mapping);
template <> const char*
  MappedType<Events::HostCheck>::table("host");

// HostDependency mapping.
template <> const MappedData<Events::HostDependency>*
  MappedType<Events::HostDependency>::members(host_dependency_mapping);
template <> const char*
  MappedType<Events::HostDependency>::table("host_dependency");

// HostGroup mapping.
template <> const MappedData<Events::HostGroup>*
  MappedType<Events::HostGroup>::members(host_group_mapping);
template <> const char*
  MappedType<Events::HostGroup>::table("hostgroup");

// HostGroupMember mapping.
template <> const MappedData<Events::HostGroupMember>*
  MappedType<Events::HostGroupMember>::members(host_group_member_mapping);
template <> const char*
  MappedType<Events::HostGroupMember>::table("host_hostgroup");

// HostParent mapping.
template <> const MappedData<Events::HostParent>*
  MappedType<Events::HostParent>::members(host_parent_mapping);
template <> const char*
  MappedType<Events::HostParent>::table("host_parents");

// HostStatus mapping.
template <> const MappedData<Events::HostStatus>*
  MappedType<Events::HostStatus>::members(host_status_mapping);
template <> const char*
  MappedType<Events::HostStatus>::table("host");

// Log mapping.
template <> const MappedData<Events::Log>*
  MappedType<Events::Log>::members(log_mapping);
template <> const char*
  MappedType<Events::Log>::table("log");

// Program mapping.
template <> const MappedData<Events::Program>*
  MappedType<Events::Program>::members(program_mapping);
template <> const char*
  MappedType<Events::Program>::table("program_status");

// ProgramStatus mapping.
template <> const MappedData<Events::ProgramStatus>*
  MappedType<Events::ProgramStatus>::members(program_status_mapping);
template <> const char*
  MappedType<Events::ProgramStatus>::table("program_status");

// Service mapping.
template <> const MappedData<Events::Service>*
  MappedType<Events::Service>::members(service_mapping);
template <> const char*
  MappedType<Events::Service>::table("service");

// ServiceCheck mapping.
template <> const MappedData<Events::ServiceCheck>*
  MappedType<Events::ServiceCheck>::members(service_check_mapping);
template <> const char*
  MappedType<Events::ServiceCheck>::table("service");

// ServiceDependency mapping.
template <> const MappedData<Events::ServiceDependency>*
  MappedType<Events::ServiceDependency>::members(service_dependency_mapping);
template <> const char*
  MappedType<Events::ServiceDependency>::table("service_dependency");

// ServiceGroup mapping.
template <> const MappedData<Events::ServiceGroup>*
  MappedType<Events::ServiceGroup>::members(service_group_mapping);
template <> const char*
  MappedType<Events::ServiceGroup>::table("servicegroup");

// ServiceGroupMember mapping.
template <> const MappedData<Events::ServiceGroupMember>*
  MappedType<Events::ServiceGroupMember>::members(service_group_member_mapping);
template <> const char*
  MappedType<Events::ServiceGroupMember>::table("service_servicegroup");

// ServiceStatus mapping.
template <> const MappedData<Events::ServiceStatus>*
  MappedType<Events::ServiceStatus>::members(service_status_mapping);
template <> const char*
  MappedType<Events::ServiceStatus>::table("service");