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

  std::shared_ptr<DBFactory> dbConn = std::make_shared<MySQLFactory>(username, password, dbName, host);

  // ACT
  bool connStatus = false;
  if (dbConn->isInit()) {
    connStatus = true;
  }
  // ASSERT
  CPPUNIT_ASSERT(connStatus == true);
}
