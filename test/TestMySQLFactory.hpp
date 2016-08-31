/*
 * TestMySQLFactory.hpp
 *
 *  Created on: Aug 31, 2016
 *      Author: developer
 */

#ifndef TEST_TESTMYSQLFACTORY_HPP_
#define TEST_TESTMYSQLFACTORY_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/DBFactory.hpp"
#include "../inc/MySQLFactory.hpp"

class TestMySQLFactory : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(TestMySQLFactory);
  CPPUNIT_TEST(testCreateMySQLDatabase);
  CPPUNIT_TEST_SUITE_END();

 private:
  void testCreateMySQLDatabase();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestMySQLFactory);
#endif /* TEST_TESTMYSQLFACTORY_HPP_ */
