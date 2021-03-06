--
-- Business Activities.
--
CREATE TABLE mod_bam (
  ba_id int NOT NULL,
  name varchar(254) default NULL,

  description varchar(254) default NULL,
  level_w float default NULL,
  level_c float default NULL,
  sla_month_percent_warn float default NULL,
  sla_month_percent_crit float default NULL,
  sla_month_duration_warn int default NULL,
  sla_month_duration_crit int default NULL,
  current_level float default NULL,
  downtime float default NULL,
  acknowledged float default NULL,
  activate enum('1','0') NOT NULL default '0',
  last_state_change int default NULL,
  current_status char(1) default NULL,
  in_downtime boolean default NULL,
  must_be_rebuild enum('0', '1', '2') NOT NULL default '0',
  id_reporting_period int default NULL,

  PRIMARY KEY (ba_id),
  UNIQUE (name),
  FOREIGN KEY (id_reporting_period) REFERENCES timeperiod (tp_id)
    ON DELETE SET NULL
);
CREATE SEQUENCE mod_bam_seq
START WITH 1
INCREMENT BY 1;
CREATE TRIGGER mod_bam_trigger
BEFORE INSERT ON mod_bam
FOR EACH ROW
BEGIN
  SELECT mod_bam_seq.nextval INTO :NEW.ba_id FROM dual;
END;
/
