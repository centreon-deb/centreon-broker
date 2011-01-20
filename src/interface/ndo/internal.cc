/*
** Copyright 2009-2011 MERETHIS
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
**
** For more information: contact@centreon.com
*/

#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include "interface/ndo/internal.hh"

using namespace interface::ndo;

/**************************************
*                                     *
*          Static Functions           *
*                                     *
**************************************/

/**
 *  Get a boolean from an object.
 */
template <typename T>
static void get_boolean(T const& t,
                        data_member<T> const& member,
                        std::stringstream& buffer) {
  buffer << (t.*(member.b) ? "1" : "0");
  return ;
}

/**
 *  Get a double from an object.
 */
template <typename T>
static void get_double(T const& t,
                       data_member<T> const& member,
                       std::stringstream& buffer) {
  buffer << t.*(member.d);
  return ;
}

/**
 *  Get an integer from an object.
 */
template <typename T>
static void get_integer(T const& t,
                        data_member<T> const& member,
                        std::stringstream& buffer) {
  buffer << t.*(member.i);
  return ;
}

/**
 *  Get a short from an object.
 */
template <typename T>
static void get_short(T const& t,
                      data_member<T> const& member,
                      std::stringstream& buffer) {
  buffer << t.*(member.s);
  return ;
}

/**
 *  Get a string from an object.
 */
template <typename T>
static void get_string(T const& t,
                       data_member<T> const& member,
                       std::stringstream& buffer) {
  buffer << t.*(member.S);
  return ;
}

/**
 *  Get a time_t from an object.
 */
template <typename T>
static void get_timet(T const& t,
                      data_member<T> const& member,
                      std::stringstream& buffer) {
  buffer << t.*(member.t);
  return ;
}

/**
 *  Set a boolean within an object.
 */
template <typename T>
static void set_boolean(T& t,
                        data_member<T> const& member,
                        char const* str) {
  t.*(member.b) = strtol(str, NULL, 0);
  return ;
}

/**
 *  Set a double within an object.
 */
template <typename T>
static void set_double(T& t,
                       data_member<T> const& member,
                       char const* str) {
  t.*(member.d) = strtod(str, NULL);
  return ;
}

/**
 *  Set an integer within an object.
 */
template <typename T>
static void set_integer(T& t,
                        data_member<T> const& member,
                        char const* str) {
  t.*(member.i) = strtol(str, NULL, 0);
  return ;
}

/**
 *  Set a short within an object.
 */
template <typename T>
static void set_short(T& t,
                      data_member<T> const& member,
                      char const* str) {
  t.*(member.s) = strtol(str, NULL, 0);
  return ;
}

/**
 *  Set a string within an object.
 */
template <typename T>
static void set_string(T& t,
                       data_member<T> const& member,
                       char const* str) {
  t.*(member.S) = str;
  return ;
}

/**
 *  Set a time_t within an object.
 */
template <typename T>
static void set_timet(T& t,
                      data_member<T> const& member,
                      char const* str) {
  t.*(member.t) = strtol(str, NULL, 0);
  return ;
}

/**
 *  Static initialization template used by Initialize().
 */
template <typename T>
static void static_init() {
  for (unsigned int i = 0; mapped_type<T>::members[i].type; ++i)
    if (mapped_type<T>::members[i].id) {
      getter_setter<T>& gs(ndo_mapped_type<T>::map[mapped_type<T>::members[i].id]);
      gs.member = &mapped_type<T>::members[i].member;
      switch (mapped_type<T>::members[i].type) {
       case mapped_data<T>::BOOL:
        gs.getter = &get_boolean<T>;
        gs.setter = &set_boolean<T>;
        break ;
       case mapped_data<T>::DOUBLE:
        gs.getter = &get_double<T>;
        gs.setter = &set_double<T>;
        break ;
       case mapped_data<T>::INT:
        gs.getter = &get_integer<T>;
        gs.setter = &set_integer<T>;
        break ;
       case mapped_data<T>::SHORT:
        gs.getter = &get_short<T>;
        gs.setter = &set_short<T>;
        break ;
       case mapped_data<T>::STRING:
        gs.getter = &get_string<T>;
        gs.setter = &set_string<T>;
        break ;
       case mapped_data<T>::TIME_T:
        gs.getter = &get_timet<T>;
        gs.setter = &set_timet<T>;
        break ;
       default: // Error in one of the mappings.
        assert(false);
        abort();
      }
    }
  return ;
}

/**************************************
*                                     *
*           Global Objects            *
*                                     *
**************************************/

template <> std::map<int, getter_setter<events::acknowledgement> >
  interface::ndo::ndo_mapped_type<events::acknowledgement>::map =
    std::map<int, getter_setter<events::acknowledgement> >();
template <> std::map<int, getter_setter<events::comment> >
  interface::ndo::ndo_mapped_type<events::comment>::map =
    std::map<int, getter_setter<events::comment> >();
template <> std::map<int, getter_setter<events::custom_variable> >
  interface::ndo::ndo_mapped_type<events::custom_variable>::map =
    std::map<int, getter_setter<events::custom_variable> >();
template <> std::map<int, getter_setter<events::custom_variable_status> >
  interface::ndo::ndo_mapped_type<events::custom_variable_status>::map =
    std::map<int, getter_setter<events::custom_variable_status> >();
template <> std::map<int, getter_setter<events::downtime> >
  interface::ndo::ndo_mapped_type<events::downtime>::map =
    std::map<int, getter_setter<events::downtime> >();
template <> std::map<int, getter_setter<events::event_handler> >
  interface::ndo::ndo_mapped_type<events::event_handler>::map =
    std::map<int, getter_setter<events::event_handler> >();
template <> std::map<int, getter_setter<events::flapping_status> >
  interface::ndo::ndo_mapped_type<events::flapping_status>::map =
    std::map<int, getter_setter<events::flapping_status> >();
template <> std::map<int, getter_setter<events::host> >
  interface::ndo::ndo_mapped_type<events::host>::map =
    std::map<int, getter_setter<events::host> >();
template <> std::map<int, getter_setter<events::host_check> >
  interface::ndo::ndo_mapped_type<events::host_check>::map =
    std::map<int, getter_setter<events::host_check> >();
template <> std::map<int, getter_setter<events::host_dependency> >
  interface::ndo::ndo_mapped_type<events::host_dependency>::map =
    std::map<int, getter_setter<events::host_dependency> >();
template <> std::map<int, getter_setter<events::host_group> >
  interface::ndo::ndo_mapped_type<events::host_group>::map =
    std::map<int, getter_setter<events::host_group> >();
template <> std::map<int, getter_setter<events::host_group_member> >
  interface::ndo::ndo_mapped_type<events::host_group_member>::map =
    std::map<int, getter_setter<events::host_group_member> >();
template <> std::map<int, getter_setter<events::host_parent> >
  interface::ndo::ndo_mapped_type<events::host_parent>::map =
    std::map<int, getter_setter<events::host_parent> >();
template <> std::map<int, getter_setter<events::host_status> >
  interface::ndo::ndo_mapped_type<events::host_status>::map =
    std::map<int, getter_setter<events::host_status> >();
template <> std::map<int, getter_setter<events::instance> >
  interface::ndo::ndo_mapped_type<events::instance>::map =
    std::map<int, getter_setter<events::instance> >();
template <> std::map<int, getter_setter<events::instance_status> >
  interface::ndo::ndo_mapped_type<events::instance_status>::map =
    std::map<int, getter_setter<events::instance_status> >();
template <> std::map<int, getter_setter<events::issue> >
  interface::ndo::ndo_mapped_type<events::issue>::map =
    std::map<int, getter_setter<events::issue> >();
template <> std::map<int, getter_setter<events::issue_parent> >
  interface::ndo::ndo_mapped_type<events::issue_parent>::map =
    std::map<int, getter_setter<events::issue_parent> >();
template <> std::map<int, getter_setter<events::log_entry> >
  interface::ndo::ndo_mapped_type<events::log_entry>::map =
    std::map<int, getter_setter<events::log_entry> >();
template <> std::map<int, getter_setter<events::notification> >
  interface::ndo::ndo_mapped_type<events::notification>::map =
    std::map<int, getter_setter<events::notification> >();
template <> std::map<int, getter_setter<events::service> >
  interface::ndo::ndo_mapped_type<events::service>::map =
    std::map<int, getter_setter<events::service> >();
template <> std::map<int, getter_setter<events::service_check> >
  interface::ndo::ndo_mapped_type<events::service_check>::map =
    std::map<int, getter_setter<events::service_check> >();
template <> std::map<int, getter_setter<events::service_dependency> >
  interface::ndo::ndo_mapped_type<events::service_dependency>::map =
    std::map<int, getter_setter<events::service_dependency> >();
template <> std::map<int, getter_setter<events::service_group> >
  interface::ndo::ndo_mapped_type<events::service_group>::map =
    std::map<int, getter_setter<events::service_group> >();
template <> std::map<int, getter_setter<events::service_group_member> >
  interface::ndo::ndo_mapped_type<events::service_group_member>::map =
    std::map<int, getter_setter<events::service_group_member> >();
template <> std::map<int, getter_setter<events::service_status> >
  interface::ndo::ndo_mapped_type<events::service_status>::map =
    std::map<int, getter_setter<events::service_status> >();
template <> std::map<int, getter_setter<events::state> >
  interface::ndo::ndo_mapped_type<events::state>::map =
    std::map<int, getter_setter<events::state> >();

/**************************************
*                                     *
*          Global Functions           *
*                                     *
**************************************/

/**
 *  @brief Initialization routine.
 *
 *  Initialize NDO mappings.
 */
void interface::ndo::initialize() {
  static_init<events::acknowledgement>();
  static_init<events::comment>();
  static_init<events::custom_variable>();
  static_init<events::custom_variable_status>();
  static_init<events::downtime>();
  static_init<events::event_handler>();
  static_init<events::flapping_status>();
  static_init<events::host>();
  static_init<events::host_check>();
  static_init<events::host_dependency>();
  static_init<events::host_group>();
  static_init<events::host_group_member>();
  static_init<events::host_parent>();
  static_init<events::host_status>();
  static_init<events::instance>();
  static_init<events::instance_status>();
  static_init<events::issue>();
  static_init<events::issue_parent>();
  static_init<events::log_entry>();
  static_init<events::notification>();
  static_init<events::service>();
  static_init<events::service_check>();
  static_init<events::service_dependency>();
  static_init<events::service_group>();
  static_init<events::service_group_member>();
  static_init<events::service_status>();
  static_init<events::state>();
  return ;
}