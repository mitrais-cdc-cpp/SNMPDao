/*
 * DBConnector.cpp
 *
 *  Created on: Agust 29, 2016
 *      Author: suhendra-ep
 */

#include "../inc/DBConnector.hpp"

namespace DB {

/**
* Default Constructor
* @param username: Database username
* @param password: Database password
* @param dbName: Database name
* @param host: Database host
*/
DBConnector::DBConnector(const char* username, const char* password,
                         const char* dbName, const char* host)
    : _username(username),
      _password(password),
      _dbName(dbName),
      _host(host),
      _dbConnection(new odb::mysql::database(_username, _password, _dbName)) {}

/**
 * Default destructor
 */
DBConnector::~DBConnector() {}

/**
 * Function to insert entity
 * @param entity
 */
template <typename T>
void DBConnector::Insert(T entity) {
  try {
    transaction t(_dbConnection->begin());
    _dbConnection->persist(entity);
    t.commit();
  } catch (const odb::exception& e) {
    cerr << e.what() << endl;
  }
}
}
