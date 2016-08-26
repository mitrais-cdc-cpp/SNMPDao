#ifndef NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_
#define NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_

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
	class SnmpObjectType
	{
		public:
			SnmpObjectType(const std::string typeName,
					const unsigned long snmpObjectValueId) :
				typeName_(typeName),
				snmpObjectValueId_(snmpObjectValueId)
			{

			}

			/*
			 * Type Name
			 */
			const std::string&
			TypeName() const
			{
				return typeName_;
			}

			/*
			 * Type Name
			 */
			const unsigned long&
			SnmpObjectValueId() const
			{
				return snmpObjectValueId_;
			}

		private:
			friend class odb::access;
			SnmpObjectType ()
			{

			}
			#pragma db id auto
			unsigned long snmpObjectTypeId_;

			#pragma db type("VARCHAR(45)")
			std::string typeName_;

			unsigned long snmpObjectValueId_;
	};

	#pragma db view object(SnmpObjectType)
	struct SnmpObjectType_stat
	{
	  #pragma db column("count(" + SnmpObjectType::snmpObjectTypeId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_SNMPOBJECTTYPE_HPP_ */
