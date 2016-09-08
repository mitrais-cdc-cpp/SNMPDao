#ifndef NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_
#define NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_

#include <string>
// ODB dependencies
#include <odb/core.hxx>

#pragma db object pointer(std::shared_ptr) session
class ItemizedObject {
 public:
  ItemizedObject(const unsigned long networkElementId,
                 const unsigned long snmpObjectId)
      : networkElementId_(networkElementId), snmpObjectId_(snmpObjectId) {}

  /// TODO: missing ... Getter for NetworkElement object
  const unsigned long& NetworkElementId() const { return networkElementId_; }
  /// TODO: missing ... Getter for SnmpObject object
  const unsigned long& SnmpObjectId() const { return snmpObjectId_; }

 private:
  friend class odb::access;
  ItemizedObject() {}

/// Primary Key
#pragma db id auto
  unsigned long ItemizedObjectId_;
  /// TODO: not impl yet
  unsigned long networkElementId_;
  /// TODO: not impl yet
  unsigned long snmpObjectId_;
};

#endif /* NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_ */
