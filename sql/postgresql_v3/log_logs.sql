--
-- Centreon Engine logs.
--
CREATE TABLE log_logs (
  log_id serial,

  ctime int default NULL,
  host_id int default NULL,
  host_name varchar(255) default NULL,
  instance_name varchar(255) NOT NULL,
  issue_id default NULL,
  msg_type smallint default NULL,
  notification_cmd varchar(255) default NULL,
  notification_contact varchar(255) default NULL,
  output text default NULL,
  retry int default NULL,
  service_description varchar(255) default NULL,
  service_id int default NULL,
  status smallint default NULL,
  type smallint default NULL,

  PRIMARY KEY (log_id),
  INDEX (host_name),
  INDEX (service_description),
  INDEX (status),
  INDEX (instance_name),
  INDEX (ctime),
  INDEX (host_id, service_id, msg_type, status, ctime),
  INDEX (host_id, msg_type, status, ctime),
  INDEX (host_id, service_id, msg_type, ctime, status),
  INDEX (host_id, msg_type, ctime, status),
  FOREIGN KEY (host_id) REFERENCES rt_hosts (host_id)
    ON DELETE SET NULL
);
