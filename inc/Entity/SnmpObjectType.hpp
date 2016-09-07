#ifndef NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_
#define NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_

#include <odb/core.hxx>
#include <string>

#pragma db object
class SnmpObjectType {
 public:
  SnmpObjectType(const std::string typeName,
                 const unsigned long snmpObjectValueId)
      : typeName_(typeName) {}

  // getter
  const std::string& TypeName() const { return typeName_; }

 private:
  friend class odb::access;
  SnmpObjectType() {}

#pragma db id auto
  unsigned long snmpObjectTypeId_;

#pragma db type("VARCHAR(45)")
  std::string typeName_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_ */
