#include "../inc/MySQLFactory.hpp"

#include <odb/mysql/database.hxx>

/**
Default constructor
* @param username: Database username
* @param password: Database password
* @param dbName: Database name
* @param host: Database host
*/
DB::MySQLFactory::MySQLFactory(std::string &username_, std::string &password_,
                               std::string &dbname_, std::string &host_)
    : username(username_),
      password(password_),
      dbname(dbname_),
      host(host_),
      DB::DBFactory(std::make_shared<odb::mysql::database>(username_, password_,
                                                           dbname_, host_)) {}

/// Default destructor
DB::MySQLFactory::~MySQLFactory() {}
