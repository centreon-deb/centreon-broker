/*
** Copyright 2013,2015 Merethis
**
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

#include <QMutexLocker>
#include <QDir>
#include <QFileInfo>
#include <fstream>
#include <sstream>
#include <errno.h>
#include <cstdio>
#include "com/centreon/broker/dumper/dump.hh"
#include "com/centreon/broker/dumper/remove.hh"
#include "com/centreon/broker/dumper/internal.hh"
#include "com/centreon/broker/dumper/stream.hh"
#include "com/centreon/broker/io/events.hh"
#include "com/centreon/broker/io/exceptions/shutdown.hh"
#include "com/centreon/broker/logging/logging.hh"
#include "com/centreon/broker/misc/string.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::dumper;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  Constructor.
 *
 *  @param[in] path    Dumper path.
 *  @param[in] tagname Dumper tagname.
 */
stream::stream(
          std::string const& path,
          std::string const& tagname)
  : _path(path), _tagname(tagname) {}

/**
 *  Destructor.
 */
stream::~stream() {}

/**
 *  Read data from the dumper.
 *
 *  @param[out] d         Cleared.
 *  @param[in]  deadline  Timeout.
 *
 *  @return This method will throw.
 */
bool stream::read(misc::shared_ptr<io::data>& d, time_t deadline) {
  (void)deadline;
  d.clear();
  throw (io::exceptions::shutdown(true, false)
         << "attempt to read from dumper '" << _path << "'");
  return (true);
}

/**
 *  Write data to the dumper.
 *
 *  @param[in] d Data to write.
 *
 *  @return Always return 1, or throw exceptions.
 */
unsigned int stream::write(misc::shared_ptr<io::data> const& d) {
  // Check that data exists.
  if (d.isNull())
    return (1);

  // Check if the event is a dumper event.
  if (d->type() == dump::static_type()) {
    dump* data(static_cast<dump*>(d.data()));

    // Check if this output dump this event.
    if (data->tag.toStdString() == _tagname) {
      // Lock mutex.
      QMutexLocker lock(&_mutex);

      logging::debug(logging::medium)
        << "dumper: dumping content of file " << data->filename;

      // Get poller ID.
      std::ostringstream poller_id;
      poller_id << data->poller_id;

      // Get Broker ID.
      std::ostringstream broker_id;
      broker_id << data->source_id;

      // Build path.
      std::string path(_path);
      misc::string::replace(
                      path,
                      "$POLLERID$",
                      poller_id.str());
      misc::string::replace( // For compatibility.
                      path,
                      "$INSTANCEID$",
                      poller_id.str());
      misc::string::replace(
                      path,
                      "$BROKERID$",
                      broker_id.str());
      misc::string::replace(
                      path,
                      "$FILENAME$",
                      data->filename.toStdString());

      // Get sub directory, if any. Create it if needed.
      QDir dir = QFileInfo(QString::fromStdString(path)).dir();
      if (!dir.exists()) {
        if (!dir.mkpath(dir.path()))
          throw (exceptions::msg()
            << "dumper: can't create the directory: " << dir.path());
      }

      // Open file.
      std::ofstream file(path.c_str());
      if (!file.is_open())
        throw (exceptions::msg()
               << "dumper: error can not open file '"
               << path << "'");

      // Write data.
      file << data->content.toStdString();
    }
  }
  else if (d->type() == dumper::remove::static_type()) {
    remove const& data = d.ref_as<dumper::remove const>();
    if (data.tag.toStdString() == _tagname) {
      // Lock mutex.
      QMutexLocker lock(&_mutex);

      logging::debug(logging::medium)
        << "dumper: removing file " << data.filename;

      // Get poller ID.
      std::ostringstream poller_id;
      poller_id << data.poller_id;

      // Get Broker ID.
      std::ostringstream broker_id;
      broker_id << data.source_id;

      // Build path.
      std::string path(_path);
      misc::string::replace(
                      path,
                      "$POLLERID$",
                      poller_id.str());
      misc::string::replace( // For compatibility.
                      path,
                      "$INSTANCEID$",
                      poller_id.str());
      misc::string::replace(
                      path,
                      "$BROKERID$",
                      broker_id.str());
      misc::string::replace(
                      path,
                      "$FILENAME$",
                      data.filename.toStdString());

      // Remove file.
      if (::remove(path.c_str()) == -1) {
        const char* msg = ::strerror(errno);
        logging::error(logging::medium)
          << "dumper: can't erase file '" << path << "': " << msg;
      }
    }
  }
  else
    logging::info(logging::low) << "dumper: write request with "
      "invalid data (" << d->type() << ")";
  return (1);
}
