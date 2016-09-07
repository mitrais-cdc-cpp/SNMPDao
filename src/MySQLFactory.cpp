#include "../inc/MySQLFactory.hpp"

/**
Default constructor
* @param username: Database username
* @param password: Database password
* @param dbName: Database name
* @param host: Database host
*/
DB::MySQLFactory::MySQLFactory(const char *username, const char *password,
                               const char *dbName, const char *host)
    : _username(username), _password(password), _dbName(dbName), _host(host) {}

/** Default destructor
 */
DB::MySQLFactory::~MySQLFactory() {}

/** Function to create database
 * @return database pointer
 */
std::auto_ptr<odb::database> DB::MySQLFactory::createDatabase() {
  std::auto_ptr<odb::database> db(
      new odb::mysql::database(_username, _password, _dbName, _host));
  return db;
}
