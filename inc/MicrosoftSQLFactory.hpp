#ifndef INC_MSSQLFACTORY_HPP_
#define INC_MSSQLFACTORY_HPP_

#include <memory>
#include <string>
#include "DBFactory.hpp"

namespace DB {
/**
 * MicrosoftSQL Database factory
 */
class MicrosoftSQLFactory : public DBFactory {
 public:
  /**
   * Default constructor
   * @param username: Database username
   * @param password: Database password
   * @param dbName: Database name
   * @param host: Database host
   */
	MicrosoftSQLFactory(std::string &username_, std::string &password_,
               std::string &dbname_, std::string &host_);

  /// Default dtor
  ~MicrosoftSQLFactory();

  /**
   * Function to create database
   * @return database pointer
   */
  std::unique_ptr<odb::database> createDatabase();

 private:
  /// Database username
  std::string username;
  /// Database password
  std::string password;
  /// Database host
  std::string host;
  /// Database name
  std::string dbname;
};
}

#endif /* INC_MSSQLFACTORY_HPP_ */
