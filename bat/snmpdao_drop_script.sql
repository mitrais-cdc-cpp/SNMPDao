SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Table `nemstadb`.`NetworkElement`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`NetworkElement` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemstadb`.`SnmpObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`SnmpObject` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemstadb`.`ItemizedObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`ItemizedObject` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemstadb`.`SnmpObjectValue`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`SnmpObjectValue` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemstadb`.`MonitorHistory`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`MonitorHistory` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemstadb`.`SnmpObjectType`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemstadb`.`SnmpObjectType` ;
SHOW WARNINGS;

-- -----------------------------------------------------
-- Schema `nemstadb`
-- -----------------------------------------------------
DROP DATABASE IF EXISTS `nemstadb` ;
SHOW WARNINGS;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;