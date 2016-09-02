/*
 * SnmpObject.hpp
 *
 *  Created on: Aug 23, 2016
 *      Author: developer
 */

#ifndef INC_ENTITY_SNMPOBJECT_HPP_
#define INC_ENTITY_SNMPOBJECT_HPP_

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
class SnmpObject
	{
		public:
			SnmpObject(const std::string mib, const std::string oid, const std::string objectName) :
						mib_(mib), oid_(oid), objectName_(objectName)

			{

			}

			const std::string&
			Mib() const
			{
				return mib_;
			}

			const std::string&
			Oid() const
			{
				return oid_;
			}

			const std::string&
			ObjectName() const
			{
				return objectName_;
			}


		private:
			friend class odb::access;
			SnmpObject ()
			{

			}
			#pragma db id auto
			unsigned long snmpObjectId_;

			#pragma db type("VARCHAR(45)")
			std::string mib_;

			#pragma db type("VARCHAR(45)")
			std::string oid_;

			#pragma db type("VARCHAR(45)")
			std::string objectName_;

	};

	#pragma db view object(SnmpObject)
	struct SnmpObject_stat
	{
	  #pragma db column("count(" + SnmpObject::snmpObjectId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* INC_ENTITY_SNMPOBJECT_HPP_ */
