/*
 * DBFactory.hpp
 *
 *  Created on: Aug 31, 2016
 *      Author: developer
 */

#ifndef INC_DBFACTORY_HPP_
#define INC_DBFACTORY_HPP_

#include <memory>
#include <odb/database.hxx>
using namespace odb::core;

namespace DB {
class DBFactory {
 public:
  DBFactory() {}
  virtual ~DBFactory() {}
  virtual std::auto_ptr<odb::database> createDatabase() = 0;
};
}
#endif /* INC_DBFACTORY_HPP_ */
