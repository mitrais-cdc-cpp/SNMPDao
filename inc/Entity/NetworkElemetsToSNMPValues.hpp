/*
 * NetworkElemetsToSNMPValues.hpp
 *
 *  Created on: Aug 23, 2016
 *      Author: developer
 */

#ifndef INC_ENTITY_NETWORKELEMETSTOSNMPVALUES_HPP_
#define INC_ENTITY_NETWORKELEMETSTOSNMPVALUES_HPP_

#include <string>
#include <cstddef>

//#include <odb/core.hxx>

#pragma db object

namespace Mitrais
{
namespace SNMPDao
{
namespace Entity
{
class NetworkElemetsToSNMPValues
	{
		public:
			NetworkElemetsToSNMPValues(const unsigned long& snmpValuesId,
					const unsigned long networkElementId,
					const unsigned long monitorHistoryId) :
						snmpValuesId_(snmpValuesId),
						networkElementId_(networkElementId),
						monitorHistoryId_(monitorHistoryId)
			{

			}

			const unsigned long&
			SNMPValuesId() const
			{
				return snmpValuesId_;
			}

			const unsigned long&
			NetworkElementId() const
			{
				return networkElementId_;
			}

			const unsigned long&
			MonitorHistoryId() const
			{
				return monitorHistoryId_;
			}

		private:
			//friend class odb::access;
			NetworkElemetsToSNMPValues ()
			{

			}
			#pragma db id auto
			unsigned long id_;

			unsigned long snmpValuesId_;

			unsigned long networkElementId_;

			unsigned long monitorHistoryId_;
	};

	#pragma db view object(NetworkElemetsToSNMPValues)
	struct NetworkElemetsToSNMPValues_stat
	{
	  #pragma db column("count(" + NetworkElemetsToSNMPValues::id_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* INC_ENTITY_NETWORKELEMETSTOSNMPVALUES_HPP_ */
