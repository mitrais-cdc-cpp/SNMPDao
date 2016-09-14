USE [master]
GO

CREATE DATABASE [nemsta]
GO

USE [nemsta]
GO

/* 
 * Before we want to use a schema, we have to create it first!
 * Create nemsta schema
 */
IF NOT EXISTS (
SELECT  schema_name
FROM    information_schema.schemata
WHERE   schema_name = 'nemsta' ) 

BEGIN
EXEC sp_executesql N'CREATE SCHEMA nemsta'
END

/****** Object:  Table [nemsta].[itemizedobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[itemizedobject](
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
/****** Object:  Table [nemsta].[monitorhistory]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[monitorhistory](
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
/****** Object:  Table [nemsta].[networkelement]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[networkelement](
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
/****** Object:  Table [nemsta].[snmpobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[snmpobject](
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
/****** Object:  Table [nemsta].[snmpobjecttype]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[snmpobjecttype](
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
/****** Object:  Table [nemsta].[snmpobjectvalue]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemsta].[snmpobjectvalue](
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
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_NetworkElement_idx] ON [nemsta].[itemizedobject]
(
	[NetworkElementFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_ItemizedObject_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_SnmpObject1_idx] ON [nemsta].[itemizedobject]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_MonitorHistory_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_MonitorHistory_SnmpObjectValue1_idx] ON [nemsta].[monitorhistory]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectType_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectType_SnmpObjectValue1_idx] ON [nemsta].[snmpobjecttype]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectValue_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectValue_SnmpObject1_idx] ON [nemsta].[snmpobjectvalue]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [nemsta].[monitorhistory] ADD  DEFAULT (NULL) FOR [Note]
GO
ALTER TABLE [nemsta].[snmpobject] ADD  DEFAULT (NULL) FOR [ObjectName]
GO
ALTER TABLE [nemsta].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement] FOREIGN KEY([NetworkElementFk])
REFERENCES [nemsta].[networkelement] ([NetworkElementId])
GO
ALTER TABLE [nemsta].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement]
GO
ALTER TABLE [nemsta].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [nemsta].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [nemsta].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1]
GO
ALTER TABLE [nemsta].[snmpobjectvalue]  WITH CHECK ADD  CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [nemsta].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [nemsta].[snmpobjectvalue] CHECK CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]
GO

USE [master]
GO
ALTER DATABASE [nemsta] SET  READ_WRITE 
GO
