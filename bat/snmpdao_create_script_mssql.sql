USE [master]
GO

CREATE DATABASE [nemstadb]
GO

USE [nemstadb]
GO

/* 
 * Before we want to use a schema, we have to create it first!
 * Create nemstadb schema
 */
IF NOT EXISTS (
SELECT  schema_name
FROM    information_schema.schemata
WHERE   schema_name = 'nemstadb' ) 

BEGIN
EXEC sp_executesql N'CREATE SCHEMA nemstadb'
END

/****** Object:  Table [nemstadb].[itemizedobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[itemizedobject](
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
/****** Object:  Table [nemstadb].[monitorhistory]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[monitorhistory](
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
/****** Object:  Table [nemstadb].[networkelement]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[networkelement](
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
/****** Object:  Table [nemstadb].[snmpobject]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[snmpobject](
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
/****** Object:  Table [nemstadb].[snmpobjecttype]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[snmpobjecttype](
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
/****** Object:  Table [nemstadb].[snmpobjectvalue]    Script Date: 8/31/2016 2:00:09 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [nemstadb].[snmpobjectvalue](
	[SnmpObjectValueId] [int] IDENTITY(1,1) NOT NULL,
	[Value] [nvarchar](300) NOT NULL,
	[SnmpObjectFk] [int] NOT NULL,
 CONSTRAINT [PK_snmpobjectvalue_SnmpObjectValueId] PRIMARY KEY CLUSTERED 
(
	[SnmpObjectValueId] ASC,
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Index [fk_ItemizedObject_NetworkElement_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_NetworkElement_idx] ON [nemstadb].[itemizedobject]
(
	[NetworkElementFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_ItemizedObject_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_ItemizedObject_SnmpObject1_idx] ON [nemstadb].[itemizedobject]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_MonitorHistory_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_MonitorHistory_SnmpObjectValue1_idx] ON [nemstadb].[monitorhistory]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectType_SnmpObjectValue1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectType_SnmpObjectValue1_idx] ON [nemstadb].[snmpobjecttype]
(
	[SnmpObjectValueFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [fk_SnmpObjectValue_SnmpObject1_idx]    Script Date: 8/31/2016 2:00:09 PM ******/
CREATE NONCLUSTERED INDEX [fk_SnmpObjectValue_SnmpObject1_idx] ON [nemstadb].[snmpobjectvalue]
(
	[SnmpObjectFk] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [nemstadb].[monitorhistory] ADD  DEFAULT (NULL) FOR [Note]
GO
ALTER TABLE [nemstadb].[snmpobject] ADD  DEFAULT (NULL) FOR [ObjectName]
GO
ALTER TABLE [nemstadb].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement] FOREIGN KEY([NetworkElementFk])
REFERENCES [nemstadb].[networkelement] ([NetworkElementId])
GO
ALTER TABLE [nemstadb].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_NetworkElement]
GO
ALTER TABLE [nemstadb].[itemizedobject]  WITH CHECK ADD  CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [nemstadb].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [nemstadb].[itemizedobject] CHECK CONSTRAINT [itemizedobject$fk_ItemizedObject_SnmpObject1]
GO
ALTER TABLE [nemstadb].[snmpobjectvalue]  WITH CHECK ADD  CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1] FOREIGN KEY([SnmpObjectFk])
REFERENCES [nemstadb].[snmpobject] ([SnmpObjectId])
GO
ALTER TABLE [nemstadb].[snmpobjectvalue] CHECK CONSTRAINT [snmpobjectvalue$fk_SnmpObjectValue_SnmpObject1]
GO

USE [master]
GO
ALTER DATABASE [nemstadb] SET  READ_WRITE 
GO
