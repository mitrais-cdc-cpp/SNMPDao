#ifndef INC_MYSQLFACTORY_HPP_
#define INC_MYSQLFACTORY_HPP_

#include <memory>
#include <string>
#include "DBFactory.hpp"

namespace DB {
/**
 * MySQL Database factory
 */
class MySQLFactory : public DBFactory {
 public:
  /**
   * Default constructor
   * @param username: Database username
   * @param password: Database password
   * @param dbName: Database name
   * @param host: Database host
   */
  MySQLFactory(std::string username_, std::string password_,
               std::string dbname_, std::string host_);

  /// Default dtor
  ~MySQLFactory();

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

#endif /* INC_MYSQLFACTORY_HPP_ */
