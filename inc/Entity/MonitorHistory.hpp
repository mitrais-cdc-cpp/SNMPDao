#ifndef NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_
#define NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_

#include <string>
#include <cstddef>

#include <odb/core.hxx>

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
					const std::string note):
						timeStamp_(timeStamp),
						note_(note)
			{

			}

			const std::string&
			TimeStamp() const
			{
				return timeStamp_;
			}

			const std::string&
			Note() const
			{
				return note_;
			}

		private:
			//friend class odb::access;
			MonitorHistory ()
			{

			}
			#pragma db id auto
			unsigned long id_;

			std::string timeStamp_;

			std::string note_;
	};

	#pragma db view object(MonitorHistory)
	struct MonitorHistory_stat
	{
	  #pragma db column("count(" + MonitorHistory::id_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_ */
