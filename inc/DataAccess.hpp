#ifndef INC_UTIL_DATAACCESS_HPP_
#define INC_UTIL_DATAACCESS_HPP_

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "Entity/MonitorHistory.hpp"
#include "Entity/NetworkElement.hpp"
#include "Entity/SnmpObject.hpp"
#include "Entity/SnmpObjectType.hpp"
#include "Entity/SnmpObjectValue.hpp"

#include "odb_gen/MonitorHistory_odb.h"
#include "odb_gen/NetworkElement_odb.h"
#include "odb_gen/SnmpObjectType_odb.h"
#include "odb_gen/SnmpObjectValue_odb.h"
#include "odb_gen/SnmpObject_odb.h"

#include <iostream>
#include <memory>
#include <string>

#define __DEBUG

typedef odb::query<SnmpObjectType> query_snmpmobject_type;
typedef odb::result<SnmpObjectType> result_snmpmobject_type;
typedef odb::query<SnmpObject> query_snmpmobject;
typedef odb::result<SnmpObject> result_snmpmobject;
typedef odb::query<NetworkElement> query_network_element;
typedef odb::result<NetworkElement> result_network_element;

namespace DB {
class DataAccess {
 public:
  /**
   * Default constructor
   * @param dbConn: Database connection
   */
  DataAccess(std::shared_ptr<odb::database> dbConn);

  /// Default dtor
  ~DataAccess();

  /// TODO: doc
  inline bool isInit() { return (_dbConn) ? true : false; }

  /**
   * Function to insert NetworkElement
   * @param elementName : Element name
   * @param macAddress : MacAdress
   * @param ipAddress : IP Adress
   */
  long insertNetworkElement(const std::string &elementName,
                            const std::string &macAddress,
                            const std::string &ipAddress);

  /// TODO: doc
  long insertSNMPValue(const int &networkElementId, const std::string &OID,
                       const std::string &value, const std::string &typeName);

  /**
   * Function to get NetworkElement by IP Address
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
  std::shared_ptr<NetworkElement> getNetWorkElementByMacAddress(
      const std::string &macAddress);

  std::string insertSnmpObject(const std::string &MIB, const std::string &OID,
                               const std::string &objectName);

 private:
  /// Database connection member
  std::shared_ptr<odb::database> _dbConn;

  /// TODO: doc
  std::shared_ptr<SnmpObjectType> getSnmpObjectTypeByTypeName(
      const std::string &value);
  /// TODO: doc
  std::shared_ptr<SnmpObject> getSnmpObjectByOid(const std::string &value);
  /// TODO: doc
  std::shared_ptr<MonitorHistory> insertMonitorHistory(
      const unsigned long long &lastUpdate, const std::string &note);
  /// TODO: doc
  long insertSnmpObjectValue(const std::string &value,
                             std::shared_ptr<SnmpObject> snmpObject,
                             std::shared_ptr<MonitorHistory> monitorHistory,
                             std::shared_ptr<SnmpObjectType> snmpObjectType);
};
}

#endif /* INC_UTIL_DATAACCESS_HPP_ */
