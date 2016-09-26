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
  std::string username = "NemsTA";
  std::string password = "N3m5TA4adm1n";
  std::string dbName = "mydb";
  std::string host = "172.19.12.251";

  std::unique_ptr<DBFactory> dbFactory(
      new MySQLFactory(username, password, dbName, host));

  // ACT
  bool connStatus = false;
  if (dbFactory) {
    connStatus = true;
  }

  // ASSERT
  CPPUNIT_ASSERT(connStatus == true);
}
