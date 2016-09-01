USE [nemstadb]
GO

/* Drop Foreign Key Constraints
 * Because we have some foreign keys here, we shoould delete it first before delete the tables,
 * so that will not ruined the database rules 
 */
IF OBJECT_ID('nemstadb.[itemizedobject$fk_ItemizedObject_NetworkElement]') IS NOT NULL
	ALTER TABLE [nemstadb].[itemizedobject] DROP  CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement]

IF OBJECT_ID('nemstadb.[itemizedobject$fk_ItemizedObject_SnmpObject1]') IS NOT NULL
	ALTER TABLE [nemstadb].[itemizedobject] DROP  CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1]
	
IF OBJECT_ID('nemstadb.[snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]') IS NOT NULL
	ALTER TABLE [nemstadb].[snmpobjectvalue] DROP  CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]

/****** Drop Object:  Table [nemstadb].[itemizedobject] ******/
DROP TABLE [nemstadb].[itemizedobject]
GO

/****** Drop Object:  Table [nemstadb].[monitorhistory] ******/
DROP TABLE [nemstadb].[monitorhistory]
GO

/****** Drop Object:  Table [nemstadb].[networkelement] ******/
DROP TABLE [nemstadb].[networkelement]
GO

/****** Drop Object:  Table [nemstadb].[snmpobject] ******/
DROP TABLE [nemstadb].[snmpobject]
GO

/****** Drop Object:  Table [nemstadb].[snmpobjecttype] ******/
DROP TABLE [nemstadb].[snmpobjecttype]
GO

/****** Drop Object:  Table [nemstadb].[snmpobjectvalue] ******/
DROP TABLE [nemstadb].[snmpobjectvalue]
GO

USE [master]
GO

/****** Drop Object:  Database [nemstadb] ******/
DROP DATABASE [nemstadb]
GO