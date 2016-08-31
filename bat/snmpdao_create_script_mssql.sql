USE [master]
GO
/****** Object:  Database [nemstadb]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE DATABASE [nemstadb]
GO

ALTER DATABASE [nemstadb] SET COMPATIBILITY_LEVEL = 110
GO

ALTER DATABASE [nemstadb] MODIFY FILE
( NAME = N'nemstadb' , SIZE = 4096KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
GO

ALTER DATABASE [nemstadb] MODIFY FILE
( NAME = N'nemstadb_log' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO

IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [nemstadb].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [nemstadb] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [nemstadb] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [nemstadb] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [nemstadb] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [nemstadb] SET ARITHABORT OFF 
GO
ALTER DATABASE [nemstadb] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [nemstadb] SET AUTO_CREATE_STATISTICS ON 
GO
ALTER DATABASE [nemstadb] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [nemstadb] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [nemstadb] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [nemstadb] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [nemstadb] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [nemstadb] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [nemstadb] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [nemstadb] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [nemstadb] SET  DISABLE_BROKER 
GO
ALTER DATABASE [nemstadb] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [nemstadb] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [nemstadb] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [nemstadb] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [nemstadb] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [nemstadb] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [nemstadb] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [nemstadb] SET RECOVERY FULL 
GO
ALTER DATABASE [nemstadb] SET  MULTI_USER 
GO
ALTER DATABASE [nemstadb] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [nemstadb] SET DB_CHAINING OFF 
GO
ALTER DATABASE [nemstadb] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [nemstadb] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
EXEC sys.sp_db_vardecimal_storage_format N'nemstadb', N'ON'
GO
USE [nemstadb]
GO
/****** Object:  Table [dbo].[itemizedobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[itemizedobject](
	[ItemizedObjectId] [int] IDENTITY(1,1) NOT NULL,
	[NetworkElementFk] [int] NOT NULL,
	[SnmpObjectFk] [int] NOT NULL,
 CONSTRAINT [PK_itemizedobject_ItemizedObjectId] PRIMARY KEY CLUSTERED 
(
	[ItemizedObjectId] ASC,
	[NetworkElementFk] ASC,
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[monitorhistory]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[monitorhistory](
	[MonitorHistoryId] [int] IDENTITY(1,1) NOT NULL,
	[LastUpdate] [datetime2](0) NOT NULL,
	[Note] [nvarchar](45) NULL,
	[SnmpObjectValueFk] [int] NOT NULL,
 CONSTRAINT [PK_monitorhistory_MonitorHistoryId] PRIMARY KEY CLUSTERED 
(
	[MonitorHistoryId] ASC,
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[networkelement]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[networkelement](
	[NetworkElementId] [int] IDENTITY(1,1) NOT NULL,
	[ElementName] [nvarchar](45) NOT NULL,
	[MacAddress] [nvarchar](45) NOT NULL,
	[IpAddress] [nvarchar](45) NOT NULL,
 CONSTRAINT [PK_networkelement_NetworkElementId] PRIMARY KEY CLUSTERED 
(
	[NetworkElementId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
 CONSTRAINT [networkelement$MacAddress_UNIQUE] UNIQUE NONCLUSTERED 
(
	[MacAddress] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[snmpobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[snmpobject](
	[SnmpObjectId] [int] IDENTITY(1,1) NOT NULL,
	[Mib] [nvarchar](45) NOT NULL,
	[Oid] [nvarchar](45) NOT NULL,
	[ObjectName] [nvarchar](45) NULL,
 CONSTRAINT [PK_snmpobject_SnmpObjectId] PRIMARY KEY CLUSTERED 
(
	[SnmpObjectId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[snmpobjecttype]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[snmpobjecttype](
	[SnmpObjectTypeId] [int] IDENTITY(1,1) NOT NULL,
	[TypeName] [nvarchar](45) NOT NULL,
	[SnmpObjectValueFk] [int] NOT NULL,
 CONSTRAINT [PK_snmpobjecttype_SnmpObjectTypeId] PRIMARY KEY CLUSTERED 
(
	[SnmpObjectTypeId] ASC,
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[snmpobjectvalue]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[snmpobjectvalue](
	[SnmpObjectValueId] [int] IDENTITY(1,1) NOT NULL,
	[Value] [nvarchar](45) NOT NULL,
	[SnmpObjectFk] [int] NOT NULL,
 CONSTRAINT [PK_snmpobjectvalue_SnmpObjectValueId] PRIMARY KEY CLUSTERED 
(
	[SnmpObjectValueId] ASC,
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Index [fk_ItemizedObject_NetworkElement_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_NetworkElement_idx] ON [dbo].[itemizedobject]
(
	[NetworkElementFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_ItemizedObject_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_SnmpObject1_idx] ON [dbo].[itemizedobject]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_MonitorHistory_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_MonitorHistory_SnmpObjectValue1_idx] ON [dbo].[monitorhistory]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectType_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectType_SnmpObjectValue1_idx] ON [dbo].[snmpobjecttype]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectValue_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectValue_SnmpObject1_idx] ON [dbo].[snmpobjectvalue]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [dbo].[monitorhistory] ADD  DEFAULT (NULL) FOR [Note]
GO
ALTER TABLE [dbo].[snmpobject] ADD  DEFAULT (NULL) FOR [ObjectName]
GO
ALTER TABLE [dbo].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement] FOREIGN KEY([NetworkElementFk])
REFERENCES [dbo].[networkelement] ([NetworkElementId])
GO
ALTER TABLE [dbo].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement]
GO
ALTER TABLE [dbo].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [dbo].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [dbo].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1]
GO
ALTER TABLE [dbo].[snmpobjectvalue]  WITH CHECK ADD  CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [dbo].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [dbo].[snmpobjectvalue] CHECK CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.itemizedobject' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'itemizedobject'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.monitorhistory' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'monitorhistory'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.networkelement' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'networkelement'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.snmpobject' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'snmpobject'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.snmpobjecttype' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'snmpobjecttype'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_SSMA_SOURCE', @value=N'nemstadb.snmpobjectvalue' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'snmpobjectvalue'
GO
USE [master]
GO
ALTER DATABASE [nemstadb] SET  READ_WRITE 
GO
