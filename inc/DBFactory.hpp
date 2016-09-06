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

  /**
   * The function to create database connection.
   * It will be overridden on child class.
   * @return
   */
  virtual std::unique_ptr<odb::database> createDatabase() = 0;
};
}
#endif /* INC_DBFACTORY_HPP_ */
