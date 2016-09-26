#ifndef INC_MSSQLFACTORY_HPP_
#define INC_MSSQLFACTORY_HPP_

#include <memory>
#include <string>
#include "DBFactory.hpp"

namespace DB {
/**
 * MsSQL Database factory
 */
class MsSQLFactory : public DBFactory {
 public:
  /**
   * Default constructor
   * @param username: Database credential username
   * @param password: Database credential password
   * @param dbname: Database instance name
   * @param host: Database server name/address
   */
  MsSQLFactory(std::string &username_,
			std::string &password_,
			std::string &dbname_,
			std::string &host_);

  /// Default dtor
  ~MsSQLFactory();

 private:
  /// Database username
  std::string username;

  /// Database password
  std::string password;

  /// Database name
  std::string dbname;

  /// Database host
  std::string host;
};
}


#endif /* INC_MSSQLFACTORY_HPP_ */
