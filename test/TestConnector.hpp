/*
 * TestConnector.hpp
 *
 *  Created on: August 16, 2016
 *      Author: suhendra-ep
 */

#ifndef SNMP_DAO_TESTCONNECTOR_H_
#define SNMP_DAO_TESTCONNECTOR_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../inc/Connector.hpp"

class TestConnector: public CppUnit::TestFixture
{
	public:
		CPPUNIT_TEST_SUITE(TestConnector);
		CPPUNIT_TEST(testConnection);
		CPPUNIT_TEST_SUITE_END();
	private:
		void testConnection();
};

CPPUNIT_TEST_SUITE_REGISTRATION( TestConnector );
#endif /* SNMP_DAO_TESTCONNECTOR_H_ */
