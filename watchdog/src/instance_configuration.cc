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

#include "com/centreon/broker/watchdog/instance_configuration.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::watchdog;

/**
 *  Default constructor.
 */
instance_configuration::instance_configuration()
  : _run(false), _reload(false), _seconds_per_tentative(0) {}

/**
 *  Constructor.
 *
 *  @param[in] name           The name of the instance.
 *  @param[in] config_file    The config file of the instance.
 *  @param[in] should_run     Should this instance be run?
 *  @param[in] should_reload  Should this instance be reloaded on SIGHUP?
 *  @param[in] seconds_per_tentative  The number of seconds between tentatives.
 */
instance_configuration::instance_configuration(
                                 std::string const& name,
                                 std::string const& config_file,
                                 bool should_run,
                                 bool should_reload,
                                 unsigned int seconds_per_tentative)
  : _name(name),
    _config_file(config_file),
    _run(should_run),
    _reload(should_reload),
    _seconds_per_tentative(seconds_per_tentative) {}
/**
 *  Destructor.
 */
instance_configuration::~instance_configuration() {}

/**
 *  Copy constructor.
 *
 *  @param[in] other  Object to copy.
 */
instance_configuration::instance_configuration(
                                 instance_configuration const& other)
  : _name(other._name),
    _config_file(other._config_file),
    _run(other._run),
    _reload(other._reload),
   _seconds_per_tentative(other._seconds_per_tentative) {}

/**
 *  Assignment operator.
 *
 *  @param[in] other  Object to copy.
 *
 *  @return  A reference to this object.
 */
instance_configuration& instance_configuration::operator=(
                                 instance_configuration const& other) {
  if (this != &other) {
    _name = other._name;
    _config_file = other._config_file;
    _run = other._run;
    _reload = other._reload;
    _seconds_per_tentative = other._seconds_per_tentative;
  }
  return (*this);
}

/**
 *  @brief Compare two instance configuration.
 *
 *  Two instances compare true if their name, config file and run properties
 *  are the same.
 *
 *  @param[in] other  The object to compare with.
 *
 *  @return  True if equal.
 */
bool instance_configuration::operator==(
       instance_configuration const& other) const {
  return (_name == other._name
          && _config_file == other._config_file
          && _run == other._run);
}

/**
 *  @brief Unequal comparison.
 *
 *  @param[in] other  The object to compare.
 *
 *  @return  !operator==().
 */
bool instance_configuration::operator!=(
       instance_configuration const& other) const {
  return (!instance_configuration::operator==(other));
}

/**
 *  Is this configuration empty?
 *
 *  @return  True if empty.
 */
bool instance_configuration::is_empty() const throw() {
  return (_name.empty());
}

/**
 *  Get the name of this instance.
 *
 *  @return[in]  The name of this instance.
 */
std::string const& instance_configuration::get_name() const throw() {
  return (_name);
}

/**
 *  Get the configuration file for this instance.
 *
 *  @return[in]  The configuration file for this instance.
 */
std::string const&
  instance_configuration::get_config_file() const throw() {
  return (_config_file);
}

/**
 *  Should this instance be run?
 *
 *  @return  True if this instance should be run.
 */
bool instance_configuration::should_run() const throw() {
  return (_run);
}

/**
 *  Should this instance be reloaded?
 *
 *  @return  True if this instance should be reloaded.
 */
bool instance_configuration::should_reload() const throw() {
  return (_reload);
}

/**
 *  How many seconds between each tentative?
 *
 *  @return  How many seconds between restart.
 */
unsigned int instance_configuration::seconds_per_tentative() const throw() {
  return (_seconds_per_tentative == 0 ? 1 : _seconds_per_tentative);
}
