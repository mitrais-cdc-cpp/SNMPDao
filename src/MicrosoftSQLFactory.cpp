#include "../inc/MicrosoftSQLFactory.hpp"

#include <odb/mssql/database.hxx>

DB::MicrosoftSQLFactory::MicrosoftSQLFactory(std::string &username_, std::string &password_,
                               std::string &dbname_, std::string &host_)

    : username(username_),
      password(password_),
      dbname(dbname_),
      host(host_),
      DB::DBFactory(std::make_shared<odb::mssql::database>(username_, password_,
                                                           dbname_, host_))
{

}

DB::MicrosoftSQLFactory::~MicrosoftSQLFactory()
{

}
