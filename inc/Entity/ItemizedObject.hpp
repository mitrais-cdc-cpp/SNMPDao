#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

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
	class SnmpObjectValue
	{
		public:
			SnmpObjectValue(const std::string value, const unsigned long snmpObjectId) :
						value_(value), snmpObjectId_(snmpObjectId)
			{

			}

			const std::string&
			Value() const
			{
				return value_;
			}

			const unsigned long&
			SnmpObjectId() const
			{
				return snmpObjectId_;
			}

		private:
			friend class odb::access;
			SnmpObjectValue ()
			{

			}
			#pragma db id auto
			unsigned long snmpObjectValueId_;

			#pragma db type("VARCHAR(45)")
			std::string value_;

			unsigned long snmpObjectId_;
	};

	#pragma db view object(SnmpObjectValue)
	struct SnmpObjectValue_stat
	{
	  #pragma db column("count(" + SnmpObjectValue::snmpObjectValueId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
