--
-- Centreon Engine logs.
--
CREATE TABLE logs (
  log_id int NOT NULL,

  ctime int default NULL,
  host_id default NULL,
  host_name varchar(255) default NULL,
  instance_name varchar(255) NOT NULL,
  issue_id int default NULL,
  msg_type char(1) default NULL,
  notification_cmd varchar(255) default NULL,
  notification_contact varchar(255) default NULL,
  output clob default NULL,
  retry int default NULL,
  service_description varchar(255) default NULL,
  service_id int default NULL,
  status char(1) default NULL,
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
  FOREIGN KEY (host_id) REFERENCES hosts (host_id)
    ON DELETE SET NULL
);
CREATE SEQUENCE logs_seq
START WITH 1
INCREMENT BY 1;
CREATE TRIGGER logs_trigger
BEFORE INSERT ON logs
FOR EACH ROW
BEGIN
  SELECT logs_seq.nextval INTO :NEW.log_id FROM dual;
END;
/
