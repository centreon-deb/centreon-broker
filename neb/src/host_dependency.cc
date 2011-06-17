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

#include "com/centreon/broker/neb/host_dependency.hh"

using namespace com::centreon::broker::neb;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Default constructor.
 */
host_dependency::host_dependency() {}

/**
 *  Copy constructor.
 *
 *  @param[in] hd Object to copy.
 */
host_dependency::host_dependency(host_dependency const& hd)
  : dependency(hd) {}

/**
 *  Destructor.
 */
host_dependency::~host_dependency() {}

/**
 *  Assignment operator.
 *
 *  @param[in] hd Object to copy.
 *
 *  @return This object.
 */
host_dependency& host_dependency::operator=(host_dependency const& hd) {
  dependency::operator=(hd);
  return (*this);
}

/**
 *  Get the type of this object.
 *
 *  @return The string "com::centreon::broker::neb::host_dependency".
 */
QString const& host_dependency::type() const {
  static QString const hd_type("com::centreon::broker::neb::host_dependency");
  return (hd_type);
}