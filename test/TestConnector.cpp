/*
 * TestConnector.cpp
 *
 *  Created on: August 16, 2016
 *      Author: suhendra-ep
 */

#include "TestConnector.hpp"

void TestConnector::testConnection()
{
	// ARRANGE
	DB::Connector conn;
	std::string actual = "Test Connection";

	// ACT
	std::string result = conn.Connection();
	int status = result.compare(actual);

	// ASSERT
	CPPUNIT_ASSERT(status == 0);
}
