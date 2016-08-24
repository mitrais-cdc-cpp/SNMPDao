#ifndef NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_
#define NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_

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
	class NetworkElement
	{
		public:
			NetworkElement(const std::string& ipAddress,
					const std::string macAddress,
					const std::string hostName) :
						ipAddress_(ipAddress),
						macAddress_(macAddress),
						hostName_(hostName)
			{

			}

			const std::string&
			IPAddress() const
			{
				return ipAddress_;
			}

			const std::string&
			MACAddress() const
			{
				return macAddress_;
			}

			const std::string&
			HostName() const
			{
				return hostName_;
			}

		private:
			friend class odb::access;
			NetworkElement ()
			{

			}
			#pragma db id auto
			unsigned long id_;

			std::string ipAddress_;

			std::string macAddress_;

			std::string hostName_;
	};

	#pragma db view object(NetworkElement)
	struct NetworkElement_stat
	{
	  #pragma db column("count(" + NetworkElement::id_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_ */
