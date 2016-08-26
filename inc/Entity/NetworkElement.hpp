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
			NetworkElement(const std::string elementName,
					const std::string macAddress,
					const std::string& ipAddress) :
						elementName_(elementName),
						macAddress_(macAddress),
						ipAddress_(ipAddress)
			{

			}

			/*
			 * Element Name
			 */
			const std::string&
			TypeName() const
			{
				return elementName_;
			}

			/*
			 * MAC Address
			 */
			const std::string&
			MACAddress() const
			{
				return macAddress_;
			}

			/*
			 * IP Address
			 */
			const std::string&
			IPAddress() const
			{
				return ipAddress_;
			}

		private:
			friend class odb::access;
			NetworkElement ()
			{

			}
			#pragma db id auto
			unsigned long networkElementId_;

			#pragma db type("VARCHAR(45)")
			std::string elementName_;

			#pragma db type("VARCHAR(45)")
			std::string macAddress_;

			#pragma db type("VARCHAR(45)")
			std::string ipAddress_;
	};

	#pragma db view object(NetworkElement)
	struct NetworkElement_stat
	{
	  #pragma db column("count(" + NetworkElement::networkElementId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_NETWORKELEMENT_HPP_ */
