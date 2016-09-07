#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

#include <odb/core.hxx>
#include <string>
#include "MonitorHistory.hpp"
#include "SnmpObject.hpp"
#include "SnmpObjectType.hpp"

class SnmpObject;
class SnmpObjectType;
class MonitorHistory;

#pragma db object
class SnmpObjectValue {
 public:
  typedef ::SnmpObject snmpObjectTypeDef;
  typedef ::SnmpObjectType snmpObjectTypeTypeDef;
  typedef ::MonitorHistory monitorHistoryTypeDef;
  SnmpObjectValue(const std::string value,
                  std::auto_ptr<snmpObjectTypeDef> snmpObject,
                  std::auto_ptr<snmpObjectTypeTypeDef> snmpObjectType,
                  std::auto_ptr<monitorHistoryTypeDef> monitorHistory)
      : value_(value),
        snmpObjectFk_(snmpObject),
        snmpObjectTypeFk_(snmpObjectType),
        monitorHistoryFk_(monitorHistory) {}

  // getter
  const std::string& value() const { return value_; }
  std::auto_ptr<snmpObjectTypeDef> snmpObject() { return snmpObjectFk_; }
  std::auto_ptr<snmpObjectTypeTypeDef> snmpObjectType() {
    return snmpObjectTypeFk_;
  }
  std::auto_ptr<monitorHistoryTypeDef> monitorHistory() {
    return monitorHistoryFk_;
  }

  // setter
  void snmpObject(std::auto_ptr<snmpObjectTypeDef> snmpObject) {
    snmpObjectFk_ = snmpObject;
  }
  void snmpObjectType(std::auto_ptr<snmpObjectTypeTypeDef> snmpObjectType) {
    snmpObjectTypeFk_ = snmpObjectType;
  }
  void monitorHistory(std::auto_ptr<monitorHistoryTypeDef> monitorHistory) {
    monitorHistoryFk_ = monitorHistory;
  }

 private:
  friend class odb::access;
  SnmpObjectValue() {}

#pragma db id auto
  unsigned long snmpObjectValueId_;

#pragma db type("VARCHAR(45)")
  std::string value_;

#pragma db not_null
  std::auto_ptr<snmpObjectTypeDef> snmpObjectFk_;

#pragma db not_null
  std::auto_ptr<snmpObjectTypeTypeDef> snmpObjectTypeFk_;

#pragma db not_null
  std::auto_ptr<monitorHistoryTypeDef> monitorHistoryFk_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
