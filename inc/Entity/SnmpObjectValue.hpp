#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

#include <string>
// ODB dependencies
#include <odb/core.hxx>
// Aditional
#include "MonitorHistory.hpp"
#include "SnmpObject.hpp"
#include "SnmpObjectType.hpp"

class SnmpObject;
class SnmpObjectType;
class MonitorHistory;

#pragma db object pointer(std::shared_ptr) session
class SnmpObjectValue {
 public:
  typedef ::SnmpObject snmpObjectTypeDef;
  typedef ::SnmpObjectType snmpObjectTypeTypeDef;
  typedef ::MonitorHistory monitorHistoryTypeDef;
  SnmpObjectValue(const std::string value,
                  std::shared_ptr<snmpObjectTypeDef> snmpObject,
                  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType,
                  std::shared_ptr<monitorHistoryTypeDef> monitorHistory)
      : value_(value),
        snmpObjectFk_(snmpObject),
        snmpObjectTypeFk_(snmpObjectType),
        monitorHistoryFk_(monitorHistory) {}

  /// Getter for snmp value
  const std::string& value() const { return value_; }
  /// Getter for related SNMP object
  std::shared_ptr<snmpObjectTypeDef> snmpObject() { return snmpObjectFk_; }
  /// Getter for related SNMP object type
  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType() {
    return snmpObjectTypeFk_;
  }
  /// Getter for related monitor history
  std::shared_ptr<monitorHistoryTypeDef> monitorHistory() {
    return monitorHistoryFk_;
  }

  /// Setter for snmp value
  void value(std::string& value) { value_ = value; }
  /// Setter for related SNMP Object
  void snmpObject(std::shared_ptr<snmpObjectTypeDef> snmpObject) {
    snmpObjectFk_ = snmpObject;
  }
  /// Setter for related SNMP object type
  void snmpObjectType(std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType) {
    snmpObjectTypeFk_ = snmpObjectType;
  }
  /// Setter for related monitor history
  void monitorHistory(std::shared_ptr<monitorHistoryTypeDef> monitorHistory) {
    monitorHistoryFk_ = monitorHistory;
  }

 private:
  friend class odb::access;
  SnmpObjectValue() {}
/// TODO: doc
#pragma db id auto
  unsigned long snmpObjectValueId_;
/// TODO: doc
#pragma db type("VARCHAR(300)")
  std::string value_;
/// TODO: doc
#pragma db not_null
  std::shared_ptr<snmpObjectTypeDef> snmpObjectFk_;
/// TODO: doc
#pragma db not_null
  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectTypeFk_;
/// TODO: doc
#pragma db not_null
  std::shared_ptr<monitorHistoryTypeDef> monitorHistoryFk_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
