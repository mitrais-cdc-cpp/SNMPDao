#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

#include <boost/shared_ptr.hpp>
#include <cstddef>
#include <odb/core.hxx>
#include <string>
#include "MonitorHistory.hpp"
#include "SnmpObject.hpp"
#include "SnmpObjectType.hpp"

namespace Mitrais {
namespace SNMPDao {
namespace Entity {
class SnmpObject;
class SnmpObjectType;
class MonitorHistory;

#pragma db object
class SnmpObjectValue {
 public:
  typedef ::Mitrais::SNMPDao::Entity::SnmpObject snmpObjectTypeDef;
  typedef ::Mitrais::SNMPDao::Entity::SnmpObjectType snmpObjectTypeTypeDef;
  typedef ::Mitrais::SNMPDao::Entity::MonitorHistory monitorHistoryTypeDef;
  SnmpObjectValue(const std::string value,
                  boost::shared_ptr<snmpObjectTypeDef> snmpObject,
                  boost::shared_ptr<snmpObjectTypeTypeDef> monitorHistory,
                  boost::shared_ptr<monitorHistoryTypeDef> snmpObjectType)
      : value_(value),
        snmpObject_(snmpObject),
        snmpObjectType_(snmpObjectType),
        monitorHistory_(monitorHistory) {}

  const std::string& value() const { return value_; }

  void snmpObject(boost::shared_ptr<snmpObjectTypeDef> snmpObject) {
    snmpObject_ = snmpObject;
  }

  void snmpObjectType(boost::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType) {
    snmpObjectType_ = snmpObjectType;
  }

  void monitorHistory(boost::shared_ptr<monitorHistoryTypeDef> monitorHistory) {
    monitorHistory_ = monitorHistory;
  }

  boost::shared_ptr<snmpObjectTypeDef> snmpObject() const {
    return snmpObject_;
  }
  boost::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType() const {
    return snmpObjectType_;
  }
  boost::shared_ptr<monitorHistoryTypeDef> monitorHistory() const {
    return monitorHistory_;
  }

 private:
  friend class odb::access;
  SnmpObjectValue() {}
#pragma db id auto
  unsigned long snmpObjectValueId_;

#pragma db type("VARCHAR(45)")
  std::string value_;

#pragma db not_null
  boost::shared_ptr<snmpObjectTypeDef> snmpObject_;

#pragma db not_null
  boost::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType_;

#pragma db not_null
  boost::shared_ptr<monitorHistoryTypeDef> monitorHistory_;
};

#pragma db view object(SnmpObjectValue)
struct SnmpObjectValue_stat {
#pragma db column("count(" + SnmpObjectValue::snmpObjectValueId_ + ")")
  std::size_t count;
};
}
}
}

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
