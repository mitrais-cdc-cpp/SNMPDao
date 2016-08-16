/*
 * Connector.cpp
 *
 *  Created on: Agust 16, 2016
 *      Author: suhendra-ep
 */

#include <iostream>
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
	void Connector::MakeConnection()
	{
		std::cout << "Test Connection" << std::endl;
	}
}
