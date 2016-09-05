#ifndef NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_
#define NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_

#include <cstddef>
#include <memory>
#include <odb/core.hxx>
#include <string>

#pragma db object pointer(std::shared_ptr) session
class SnmpObjectType {
 public:
  SnmpObjectType(const std::string typeName,
                 const unsigned long snmpObjectValueId)
      : typeName_(typeName) {}

  /*
   * Type Name
   */
  const std::string& TypeName() const { return typeName_; }

  /*
   * Type Name
   */

 private:
  friend class odb::access;
  SnmpObjectType() {}
#pragma db id auto
  unsigned long snmpObjectTypeId_;

#pragma db type("VARCHAR(45)")
  std::string typeName_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_ */
