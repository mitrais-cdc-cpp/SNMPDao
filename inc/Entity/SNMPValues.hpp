#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

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
	class SNMPValues
	{
		public:
			SNMPValues(const std::string& mib,
					const std::string oid,
					const std::string value) :
						mib_(mib),
						oid_(oid),
						value_(value)
			{

			}

			const std::string&
			MIB() const
			{
				return mib_;
			}

			const std::string&
			OID() const
			{
				return oid_;
			}

			const std::string&
			Value() const
			{
				return value_;
			}

		private:
			//friend class odb::access;
			SNMPValues ()
			{

			}
			#pragma db id auto
			unsigned long id_;

			std::string mib_;

			std::string oid_;

			std::string value_;
	};

	#pragma db view object(SNMPValues)
	struct SNMPValues_stat
	{
	  #pragma db column("count(" + SNMPValues::id_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
