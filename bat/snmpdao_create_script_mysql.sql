-- MySQL Script generated by MySQL Workbench
-- 09/01/16 13:26:48
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema nemsta
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema nemsta
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `nemsta` DEFAULT CHARACTER SET utf8 ;
SHOW WARNINGS;
USE `nemsta` ;

-- -----------------------------------------------------
-- Table `nemsta`.`NetworkElement`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`NetworkElement` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`NetworkElement` (
  `NetworkElementId` INT NOT NULL AUTO_INCREMENT,
  `ElementName` VARCHAR(45) NOT NULL,
  `MacAddress` VARCHAR(45) NOT NULL,
  `IpAddress` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`NetworkElementId`),
  UNIQUE INDEX `MacAddress_UNIQUE` (`MacAddress` ASC))
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObject` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`SnmpObject` (
  `SnmpObjectId` INT NOT NULL AUTO_INCREMENT,
  `Mib` VARCHAR(45) NOT NULL,
  `Oid` VARCHAR(45) NOT NULL,
  `ObjectName` VARCHAR(100) NULL,
  PRIMARY KEY (`SnmpObjectId`))
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`ItemizedObject`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`ItemizedObject` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`ItemizedObject` (
  `ItemizedObjectId` INT NOT NULL AUTO_INCREMENT,
  `NetworkElementFk` INT NOT NULL,
  `SnmpObjectFk` INT NOT NULL,
  PRIMARY KEY (`ItemizedObjectId`, `NetworkElementFk`, `SnmpObjectFk`),
  INDEX `fk_ItemizedObject_NetworkElement_idx` (`NetworkElementFk` ASC),
  INDEX `fk_ItemizedObject_SnmpObject1_idx` (`SnmpObjectFk` ASC),
  CONSTRAINT `fk_ItemizedObject_NetworkElement`
    FOREIGN KEY (`NetworkElementFk`)
    REFERENCES `nemsta`.`NetworkElement` (`NetworkElementId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ItemizedObject_SnmpObject1`
    FOREIGN KEY (`SnmpObjectFk`)
    REFERENCES `nemsta`.`SnmpObject` (`SnmpObjectId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`MonitorHistory`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`MonitorHistory` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`MonitorHistory` (
  `MonitorHistoryId` INT NOT NULL AUTO_INCREMENT,
  `LastUpdate` DATETIME NOT NULL,
  `Note` VARCHAR(45) NULL,
  PRIMARY KEY (`MonitorHistoryId`))
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObjectType`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObjectType` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`SnmpObjectType` (
  `SnmpObjectTypeId` INT NOT NULL AUTO_INCREMENT,
  `TypeName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`SnmpObjectTypeId`),
  UNIQUE(`TypeName`))
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `nemsta`.`SnmpObjectValue`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `nemsta`.`SnmpObjectValue` ;

SHOW WARNINGS;
CREATE TABLE IF NOT EXISTS `nemsta`.`SnmpObjectValue` (
  `SnmpObjectValueId` INT NOT NULL AUTO_INCREMENT,
  `Value` VARCHAR(300) NOT NULL,
  `SnmpObjectFk` INT NOT NULL,
  `MonitorHistoryFk` INT NOT NULL,
  `SnmpObjectTypeFk` INT NOT NULL,
  PRIMARY KEY (`SnmpObjectValueId`, `SnmpObjectFk`, `MonitorHistoryFk`, `SnmpObjectTypeFk`),
  INDEX `fk_SnmpObjectValue_SnmpObject1_idx` (`SnmpObjectFk` ASC),
  INDEX `fk_SnmpObjectValue_MonitorHistory1_idx` (`MonitorHistoryFk` ASC),
  INDEX `fk_SnmpObjectValue_SnmpObjectType1_idx` (`SnmpObjectTypeFk` ASC),
  CONSTRAINT `fk_SnmpObjectValue_SnmpObject1`
    FOREIGN KEY (`SnmpObjectFk`)
    REFERENCES `nemsta`.`SnmpObject` (`SnmpObjectId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_SnmpObjectValue_MonitorHistory1`
    FOREIGN KEY (`MonitorHistoryFk`)
    REFERENCES `nemsta`.`MonitorHistory` (`MonitorHistoryId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_SnmpObjectValue_SnmpObjectType1`
    FOREIGN KEY (`SnmpObjectTypeFk`)
    REFERENCES `nemsta`.`SnmpObjectType` (`SnmpObjectTypeId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

SHOW WARNINGS;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
