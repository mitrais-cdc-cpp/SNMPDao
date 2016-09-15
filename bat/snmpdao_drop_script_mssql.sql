USE [nemsta]
GO

/* Get current session id of NemstaUser Login*/
SELECT session_id
FROM sys.dm_exec_sessions
WHERE login_name = 'NemstaUser'
GO

/* Drop Login NemstaUser */
DROP LOGIN [NemstaUser]
GO

/* Drop Foreign Key Constraints
 * Because we have some foreign keys here, we shoould delete it first before delete the tables,
 * so that will not ruined the database rules 
 */
IF OBJECT_ID('nemsta.[itemizedobject$fk_ItemizedObject_NetworkElement]') IS NOT NULL
	ALTER TABLE [nemsta].[itemizedobject] DROP  CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement]

IF OBJECT_ID('nemsta.[itemizedobject$fk_ItemizedObject_SnmpObject1]') IS NOT NULL
	ALTER TABLE [nemsta].[itemizedobject] DROP  CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1]
	
IF OBJECT_ID('nemsta.[snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]') IS NOT NULL
	ALTER TABLE [nemsta].[snmpobjectvalue] DROP  CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]

/****** Drop Object:  Table [nemsta].[itemizedobject] ******/
DROP TABLE [nemsta].[itemizedobject]
GO

/****** Drop Object:  Table [nemsta].[monitorhistory] ******/
DROP TABLE [nemsta].[monitorhistory]
GO

/****** Drop Object:  Table [nemsta].[networkelement] ******/
DROP TABLE [nemsta].[networkelement]
GO

/****** Drop Object:  Table [nemsta].[snmpobject] ******/
DROP TABLE [nemsta].[snmpobject]
GO

/****** Drop Object:  Table [nemsta].[snmpobjecttype] ******/
DROP TABLE [nemsta].[snmpobjecttype]
GO

/****** Drop Object:  Table [nemsta].[snmpobjectvalue] ******/
DROP TABLE [nemsta].[snmpobjectvalue]
GO

USE [master]
GO

/****** Drop Object:  Database [nemsta] ******/
DROP DATABASE [nemsta]
GO