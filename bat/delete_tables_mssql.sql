BEGIN TRAN
DELETE FROM nemsta.itemizedobject;
DELETE FROM nemsta.monitorhistory;
DELETE FROM nemsta.networkelement;
DELETE FROM nemsta.snmpobject;
DELETE FROM nemsta.snmpobjecttype;
DELETE FROM nemsta.snmpobjectvalue;
ROLLBACK;
GO