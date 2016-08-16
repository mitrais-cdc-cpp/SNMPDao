/*
 * Connector.hpp
 *
 *  Created on: Agust 16, 2016
 *      Author: suhendra-ep
 */

#ifndef INC_CONNECTOR_H_
#define INC_CONNECTOR_H_

#include <string>
#include <iostream>
namespace DB
{
	/**
	 * This class just for initial implementation
	 * TODO Suhendra: Change for the real implementation
	 */
	class Connector
	{
		public:
			/**
			 * Default constructor
			 */
			Connector();

			/**
			 * Default destructor
			 */
			~Connector();

			/**
			 * Simple method to print the text
			 * TODO Suhendra: Rename or change for the real implementation
			 */
			std::string Connection();
		private:
	};
}
#endif /* INC_CONNECTOR_H_ */
