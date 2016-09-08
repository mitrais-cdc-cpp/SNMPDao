#ifndef NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_
#define NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_

#include <string>
// ODB dependencies
#include <odb/core.hxx>

#pragma db object pointer(std::shared_ptr) session
class SnmpObjectType {
 public:
  SnmpObjectType(const std::string& typeName,
                 const unsigned long snmpObjectValueId)
      : typeName_(typeName) {}

  /// Getter for type name
  const std::string& TypeName() const { return typeName_; }

 private:
  friend class odb::access;
  SnmpObjectType() {}
/// TODO: doc
#pragma db id auto
  unsigned long snmpObjectTypeId_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string typeName_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_ */
