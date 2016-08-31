/*
 * TestMySQLFactory.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: developer
 */

#include "TestMySQLFactory.hpp"
using namespace DB;

void TestMySQLFactory::testCreateMySQLDatabase() {
  // ARRANGE
  const char *username = "NemsTA";
  const char *password = "N3m5TA4adm1n";
  const char *dbName = "mydb";
  const char *host = "172.19.12.251";

  std::unique_ptr<DBFactory> dbFactory(
      new MySQLFactory(username, password, dbName, host));

  // ACT
  bool connStatus = false;
  std::unique_ptr<database> dbConn(dbFactory->createDatabase());
  if (dbConn) {
    connStatus = true;
  }
  // ASSERT
  CPPUNIT_ASSERT(connStatus == true);
}
