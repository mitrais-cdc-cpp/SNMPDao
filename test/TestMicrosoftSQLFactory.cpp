#include "TestMicrosoftSQLFactory.hpp"
using namespace DB;

void TestMicrosoftSQLFactory::testCreateMicrosoftSQLDatabase() {
  // ARRANGE
  std::string username = "sa";
  std::string password = "N3mst4DB";
  std::string dbName = "nemstadb";
  std::string host = "172.19.12.251";

  std::unique_ptr<DBFactory> dbFactory(
      new MicrosoftSQLFactory(username, password, dbName, host));

  // ACT
  bool connStatus = false;
  if (dbFactory) {
    connStatus = true;
  }

  // ASSERT
  CPPUNIT_ASSERT(connStatus == true);
}
