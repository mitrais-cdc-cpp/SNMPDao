/*
 * TestMicrosoftSQLFactory.hpp
 *
 *  Created on: Sep 26, 2016
 *      Author: developer
 */

#ifndef TEST_TESTMICROSOFTSQLFACTORY_HPP_
#define TEST_TESTMICROSOFTSQLFACTORY_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/DBFactory.hpp"
#include "../inc/MicrosoftSQLFactory.hpp"

class TestMicrosoftSQLFactory : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(TestMicrosoftSQLFactory);
  CPPUNIT_TEST(testCreateMicrosoftSQLDatabase);
  CPPUNIT_TEST_SUITE_END();

 private:
  void testCreateMicrosoftSQLDatabase();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestMicrosoftSQLFactory);
#endif /* TEST_TESTMICROSOFTSQLFACTORY_HPP_ */
