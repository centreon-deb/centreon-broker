#!/bin/sh

## Copyright © 2016 Sébastien Gross <seb•ɑƬ•chezwam•ɖɵʈ•org>
#
## Created: 2016-02-12
## Last changed: 2016-02-12 11:51:11
#
## This program is free software. It comes without any warranty, to
## the extent permitted by applicable law. You can redistribute it
## and/or modify it under the terms of the Do What The Fuck You Want
## To Public License, Version 2, as published by Sam Hocevar. See
## http://sam.zoy.org/wtfpl/COPYING for more details.
#
# This work is based upon official Centreon init script.

#
# Script init
#
### BEGIN INIT INFO
# Provides:             cbd
# Required-Start:       $local_fs $network
# Required-Stop:        $local_fs $network
# Default-Start:        2 3 4 5
# Default-Stop:         0 1 6
# Short-Description:    Start daemon cbd at boot
# Description:          Enable service provided Centreon Broker
### END INIT INFO


PKGNAME=cbd
DESC="Centreon Broker"
DAEMON="/usr/bin/cbd"
PID_PATH="/var/run"
CONFIG_DIR="/etc/centreon-broker"


# Check that cbd is executable.
if [ ! -x "${DAEMON}" ] ; then
    echo "The cbwd binary can't be run."
    exit 3
fi

# Include the default user configuration if exists
[ -r /etc/default/${PKGNAME} ] && . /etc/default/${PKGNAME}

# Load the VERBOSE setting and other rcS variables
[ -f /etc/default/rcS ] && . /etc/default/rcS

# Define LSB log_* functions.
# Depend on lsb-base (>= 3.0-6) to ensure that this file is present.
. /lib/lsb/init-functions

if [ -z "${RUN_AT_STARTUP}" -o "${RUN_AT_STARTUP}" != "YES" ]; then
    log_warning_msg "Not starting $PKGNAME, edit /etc/default/$PKGNAME to start it."
    exit 0
fi

if [ -z "${USER}" ]; then
    log_warning_msg "Not starting $PKGNAME, USER not set in /etc/default/$PKGNAME."
    exit 0
fi


do_start() {
    for mod in $MODULES; do
	if ! test -e /etc/centreon-broker/$mod.xml; then
	    continue
	fi
	log_daemon_msg "Starting Centreon Broker $mod"
	start-stop-daemon --start --background --quiet \
			  --umask 002 \
			  --pidfile  ${PID_PATH}/cbd-$mod.pid \
			  --exec ${DAEMON} --make-pidfile --chuid ${USER} \
			  --user ${USER} -- /etc/centreon-broker/$mod.xml
	sleep 2
	test -e ${PID_PATH}/cbd-$mod.pid
	
	log_end_msg $?
    done
}

do_stop() {
    for mod in $MODULES; do
	_i=0
	log_daemon_msg "Stopping Centreon Broker $mod"
	start-stop-daemon --stop --quiet \
			  --pidfile  ${PID_PATH}/cbd-$mod.pid \
			  --exec ${DAEMON} --retry 5
	log_end_msg $? && rm -f ${PID_PATH}/cbd-$mod.pid
    done

}


do_reload() {
    for mod in $MODULES; do
	log_daemon_msg "Reloading Centreon Broker $mod"
	start-stop-daemon --stop --quiet --signal=HUP \
			  --pidfile  ${PID_PATH}/cbd-$mod.pid \
			  --exec ${DAEMON}
	log_end_msg $?
    done
}


do_status() {
    for mod in $MODULES; do
	if ! test -e ${PID_PATH}/cbd-$mod.pid; then
	    log_daemon_msg "$DESC $mod is not running";
	    log_end_msg 1
	    continue
	fi
	pid=$(cat ${PID_PATH}/cbd-$mod.pid)
	if test -e "/proc/$pid/cmdline"; then
	    log_daemon_msg "$DESC $mod is running";
	    log_end_msg 0
	else
	    log_daemon_msg "$DESC $mod is not running";
	    log_end_msg 1
	fi
    done
}


# Switch case.
case "$1" in
  start)
    do_start
    ;;
  stop)
    do_stop
    ;;
  restart)
    do_stop
    do_start
    ;;
  reload|force-reload)
    do_reload
    ;;
  status)
    do_status
    ;;
  *)
    echo "Usage: ${daemon_name} {start|stop|restart|reload|force-reload|status}"
    exit 3
esac
