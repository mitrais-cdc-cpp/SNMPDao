/*
 * MySQLFactory.hpp
 *
 *  Created on: Aug 31, 2016
 *      Author: developer
 */

#ifndef INC_MYSQLFACTORY_HPP_
#define INC_MYSQLFACTORY_HPP_

#include <memory>
#include <odb/mysql/database.hxx>
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
  MySQLFactory(const char *username, const char *password, const char *dbName,
               const char *host);

  /**
   * Default destructor
   */
  ~MySQLFactory();

  /**
   * Function to create database
   * @return database pointer
   */
  std::auto_ptr<odb::database> createDatabase();

 private:
  /**
   * Database username
   */
  const char *_username;

  /**
   * Database password
   */
  const char *_password;

  /**
   * Database host
   */
  const char *_host;

  /**
   * Database name
   */
  const char *_dbName;
};
}

#endif /* INC_MYSQLFACTORY_HPP_ */
