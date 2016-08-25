#ifndef NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_
#define NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_

#include <string>
#include <cstddef>

#include <odb/core.hxx>
#include "boost/date_time/posix_time/posix_time_types.hpp"

#pragma db object

namespace Mitrais
{
namespace SNMPDao
{
namespace Entity
{
	class MonitorHistory
	{
		public:
			MonitorHistory(const std::string& timeStamp,
					const std::string note, const unsigned long snmpObjectValueId):
						lastUdpate_(lastUdpate),
						note_(note),
						snmpObjectValueId_(snmpObjectValueId)
			{

			}

			const boost::posix_time::ptime&
			LastUdpate_() const
			{
				return lastUdpate_;
			}

			const std::string&
			Note() const
			{
				return note_;
			}

			const unsigned long&
			SnmpObjectValueId() const
			{
				return snmpObjectValueId_;
			}

		private:
			friend class odb::access;
			MonitorHistory ()
			{

			}
			#pragma db id auto
			unsigned long monitorHistoryId_;

			#pragma db type("DATETIME(6)")     // Microsecond precision.
			boost::posix_time::ptime lastUdpate_;

			#pragma db type("VARCHAR(45)")
			std::string note_;

			unsigned long snmpObjectValueId_;
	};

	#pragma db view object(MonitorHistory)
	struct MonitorHistory_stat
	{
	  #pragma db column("count(" + MonitorHistory::monitorHistoryId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_ */
