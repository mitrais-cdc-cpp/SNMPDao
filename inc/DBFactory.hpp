#ifndef INC_DBFACTORY_HPP_
#define INC_DBFACTORY_HPP_

#include <memory>
#include "DataAccess.hpp"

#include <odb/database.hxx>

namespace DB {
/**
 * The base class for database factory
 */
class DBFactory {
 public:
  /// Default ctor
  DBFactory() : dao(nullptr) {}

  /// Default dtor
  virtual ~DBFactory() {}

  /// public interface
  bool isInit() { return dao.isInit(); }

  /// TODO: doc
  bool insertSNMPValue(const int &networkElementId, const std::string &OID,
                       const std::string &value, const std::string &typeName) {
    return dao.insertSNMPValue(networkElementId, OID, value, typeName);
  }
  /// TODO: doc
  long insertNetworkElement(const std::string &elementName,
                            const std::string &macAddress,
                            const std::string &ipAddress) {
    return dao.insertNetworkElement(elementName, macAddress, ipAddress);
  }

  std::shared_ptr<NetworkElement> getNetworkElementById(
      unsigned long networkElementId) {
    return dao.getNetWorkElementById(networkElementId);
  }

 protected:
  /// derived ctor
  DBFactory(std::shared_ptr<odb::database> odb_impl) : dao(odb_impl) {}

 private:
  /// TODO: doc
  DataAccess dao;
};
}
#endif /* INC_DBFACTORY_HPP_ */
