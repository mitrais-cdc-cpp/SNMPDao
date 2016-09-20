#ifndef INC_ENTITY_SNMPOBJECT_HPP_
#define INC_ENTITY_SNMPOBJECT_HPP_

#include <string>
// ODB dependencies
#include <odb/core.hxx>

#pragma db object pointer(std::shared_ptr) session
class SnmpObject {
 public:
  SnmpObject(const std::string& mib, const std::string& oid,
             const std::string& objectName)
      : mib_(mib), oid_(oid), objectName_(objectName) {}

  // getter
  const std::string& Mib() const { return mib_; }
  const std::string& Oid() const { return oid_; }
  const std::string& ObjectName() const { return objectName_; }

 private:
  friend class odb::access;
  SnmpObject() {}
/// TODO: doc
#pragma db id auto
  unsigned long snmpObjectId_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string mib_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string oid_;
/// TODO: doc
#pragma db type("VARCHAR(100)")
  std::string objectName_;
};

#endif /* INC_ENTITY_SNMPOBJECT_HPP_ */
