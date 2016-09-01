/*
 * MySQLFactory.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: developer
 */

#include "../inc/MySQLFactory.hpp"

namespace DB {
/**
* Default constructor
* @param username: Database username
* @param password: Database password
* @param dbName: Database name
* @param host: Database host
*/
MySQLFactory::MySQLFactory(const char *username, const char *password,
                           const char *dbName, const char *host)
    : _username(username), _password(password), _dbName(dbName), _host(host) {}

/**
 * Default destructor
 */
MySQLFactory::~MySQLFactory() {}

/**
* Function to create database
* @return database pointer
*/
std::auto_ptr<odb::database> MySQLFactory::createDatabase() {
  std::auto_ptr<odb::database> db(
      new odb::mysql::database(_username, _password, _dbName, _host));
  return db;
}
}
