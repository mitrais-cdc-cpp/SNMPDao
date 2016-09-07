#ifndef NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_
#define NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_

#include <odb/core.hxx>
#include <string>

#pragma db object
class ItemizedObject {
 public:
  ItemizedObject(const unsigned long networkElementId,
                 const unsigned long snmpObjectId)
      : networkElementId_(networkElementId), snmpObjectId_(snmpObjectId) {}

  const unsigned long& NetworkElementId() const { return networkElementId_; }
  const unsigned long& SnmpObjectId() const { return snmpObjectId_; }

 private:
  friend class odb::access;
  ItemizedObject() {}

#pragma db id auto
  unsigned long ItemizedObjectId_;

  unsigned long networkElementId_;

  unsigned long snmpObjectId_;
};

#endif /* NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_ */
