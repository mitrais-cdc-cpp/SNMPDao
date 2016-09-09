#include "../inc/DataAccess.hpp"
#include <odb/mysql/database.hxx>

DB::DataAccess::DataAccess(std::shared_ptr<odb::database> dbConn)
    : _dbConn(dbConn) {}

DB::DataAccess::~DataAccess() {}

long DB::DataAccess::insertNetworkElement(const std::string& elementName,
                                          const std::string& macAddress,
                                          const std::string& ipAddress) {
  odb::transaction t(_dbConn->begin());
  try {
    NetworkElement element(elementName, macAddress, ipAddress);
    long id = _dbConn->persist(element);
    t.commit();

    return id;
  } catch (const odb::exception& e) {
    t.rollback();
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

long DB::DataAccess::insertSNMPValue(const int& networkElementId,
                                     const std::string& OID,
                                     const std::string& value,
                                     const std::string& typeName) {
  long snmpValueId = -1;
  odb::transaction t(_dbConn->begin());
  try {
    std::shared_ptr<SnmpObjectType> snmpObjectType(
        getSnmpObjectTypeByTypeName(typeName));
    std::shared_ptr<SnmpObject> snmpObject(getSnmpObjectByOid(OID));
    std::shared_ptr<MonitorHistory> monitorHistory(
        insertMonitorHistory(12345, "Test"));

    snmpValueId = insertSnmpObjectValue(value, snmpObject, monitorHistory,
                                        snmpObjectType);
#ifdef __DEBUG
    std::cout << "Mib SnmpObject : " << snmpObject->Mib() << std::endl;
    std::cout << "Typename : " << snmpObjectType->TypeName() << std::endl;
    std::cout << "SnmpValue Id : " << snmpValueId << std::endl;
#endif

    t.commit();
  } catch (const odb::exception& e) {
    t.rollback();
  }

  return snmpValueId;
}

std::shared_ptr<NetworkElement> DB::DataAccess::getNetWorkElementByMacAddress(
    const std::string& macAddress) {
  odb::transaction t(_dbConn->begin());

  // Network element
  std::shared_ptr<NetworkElement> element;
  try {
    result_network_element r(_dbConn->query<NetworkElement>(
        query_network_element::macAddress == macAddress));
    if (r.size() > 0) {
      result_network_element::iterator i(r.begin());

      element = std::shared_ptr<NetworkElement>(i.load());
      t.commit();
      return element;
    } else {
      return element;
    }
  } catch (const odb::exception& e) {
    t.rollback();
    std::cerr << e.what() << std::endl;
    return element;
  }
}

// TODO: give back collection of SnmpObjectType
std::shared_ptr<SnmpObjectType> DB::DataAccess::getSnmpObjectTypeByTypeName(
    const std::string& value) {
  std::shared_ptr<SnmpObjectType> object1;

  result_snmpmobject_type r(_dbConn->query<SnmpObjectType>(
      query_snmpmobject_type::typeName == value));

  if (r.size() > 0) {
    result_snmpmobject_type::iterator i(r.begin());
    object1 = std::shared_ptr<SnmpObjectType>(i.load());
    return object1;
  } else {
    return object1;
  }
}

std::shared_ptr<SnmpObject> DB::DataAccess::getSnmpObjectByOid(
    const std::string& value) {
  std::shared_ptr<SnmpObject> object;

  result_snmpmobject r(
      _dbConn->query<SnmpObject>(query_snmpmobject::oid == value));

  if (r.size() > 0) {
    result_snmpmobject::iterator i(r.begin());

    object = std::shared_ptr<SnmpObject>(i.load());
    return object;
  } else {
    return object;
  }
}

std::shared_ptr<MonitorHistory> DB::DataAccess::insertMonitorHistory(
    const unsigned long long& lastUpdate, const std::string& note) {
  std::shared_ptr<MonitorHistory> entity(new MonitorHistory(lastUpdate, note));
  _dbConn->persist(*entity);

  return entity;
}

long DB::DataAccess::insertSnmpObjectValue(
    const std::string& value, std::shared_ptr<SnmpObject> snmpObject,
    std::shared_ptr<MonitorHistory> monitorHistory,
    std::shared_ptr<SnmpObjectType> snmpObjectType) {
  std::shared_ptr<SnmpObjectValue> entity(
      new SnmpObjectValue(value, snmpObject, snmpObjectType, monitorHistory));
  long id = _dbConn->persist(*entity);
  return id;
}
