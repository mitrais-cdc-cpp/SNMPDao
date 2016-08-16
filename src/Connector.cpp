/*
 * Connector.cpp
 *
 *  Created on: Agust 16, 2016
 *      Author: suhendra-ep
 */

#include "../inc/Connector.hpp"

namespace DB
{
	/**
	* Default constructor
	*/
	Connector::Connector()
	{
	}

	/**
	 * Default destructor
	 */
	Connector::~Connector()
	{
	}

	/**
	* Simple method to print the text
	* TODO Suhendra: Rename or change for the real implementation
	*/
	std::string Connector::Connection()
	{
		return "Test Connection";
	}
}
