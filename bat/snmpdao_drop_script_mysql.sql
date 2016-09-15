SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Table `nemsta`.`NetworkElement`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`NetworkElement` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObject` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`ItemizedObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`ItemizedObject` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObjectValue`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObjectValue` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`MonitorHistory`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`MonitorHistory` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObjectType`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObjectType` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Schema `nemsta`
-- -----------------------------------------------------
DROP DATABASE IF EXISTS `nemsta` ;
SHOW WARNINGS;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
