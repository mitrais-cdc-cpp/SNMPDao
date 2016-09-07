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

namespace DB {
/**
 * The base class for database factory
 */
class DBFactory {
 public:
  /**
   * Default constructor
   */
  DBFactory() {}

  /**
   * Default destructor
   */
  virtual ~DBFactory() {}
  // interface
  virtual std::auto_ptr<odb::core::database> createDatabase() = 0;
};
}
#endif /* INC_DBFACTORY_HPP_ */
