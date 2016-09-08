#ifndef NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_
#define NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_

#include <string>
// ODB dependencies
#include <odb/core.hxx>

#pragma db object pointer(std::shared_ptr) session
class NetworkElement {
 public:
  NetworkElement(const std::string& elementName, const std::string& macAddress,
                 const std::string& ipAddress)
      : elementName_(elementName),
        macAddress_(macAddress),
        ipAddress_(ipAddress) {}

  const std::string& TypeName() const { return elementName_; }
  const std::string& MACAddress() const { return macAddress_; }
  const std::string& IPAddress() const { return ipAddress_; }

 private:
  friend class odb::access;
  NetworkElement() {}
/// TODO: doc
#pragma db id auto
  unsigned long networkElementId_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string elementName_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string macAddress_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string ipAddress_;
};

#endif /* NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_ */
