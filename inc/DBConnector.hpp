/*
 * Connector.hpp
 *
 *  Created on: Agust 16, 2016
 *      Author: suhendra-ep
 */

#ifndef INC_DB_CONNECTOR_H_
#define INC_DB_CONNECTOR_H_

#include <iostream>
#include <iostream>
#include <memory>  // std::auto_ptr
#include <odb/database.hxx>
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include <string>

using namespace std;
using namespace odb::core;
namespace DB {
/**
 * Database connector class
 */
class DBConnector {
 public:
  /**
   * Default Constructor
   * @param username: Database username
   * @param password: Database password
   * @param dbName: Database name
   * @param host: Database host
   */
  DBConnector(const char *username, const char *password, const char *dbName,
              const char *host);

  /**
   * Default destructor
   */
  ~DBConnector();

  /**
   * Function to insert entity to database
   * @param entity
   */
  template <typename T>
  void Insert(T entity);

  /**
   * Function to update entity
   * @param entity
   */
  template <typename T>
  void Update(T entity);

  /**
   * Function to delete entity
   * @param entity
   */
  template <typename T>
  void Delete(T entity);

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

  /**
   * Database connection
   */
  auto_ptr<database> _dbConnection;

  /**
   * Function to create database connection
   * @return
   */
  auto_ptr<database> createConnection();
};
}
#endif /* INC_CONNECTOR_H_ */
