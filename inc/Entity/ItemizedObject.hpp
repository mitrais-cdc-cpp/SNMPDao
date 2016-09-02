#ifndef NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_
#define NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_

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
	class ItemizedObject
	{
		public:
			ItemizedObject(const unsigned long networkElementId, const unsigned long snmpObjectId) :
						networkElementId_(networkElementId), snmpObjectId_(snmpObjectId)
			{

			}

			const unsigned long&
			NetworkElementId() const
			{
				return networkElementId_;
			}

			const unsigned long&
			SnmpObjectId() const
			{
				return snmpObjectId_;
			}

		private:
			friend class odb::access;
			ItemizedObject ()
			{

			}
			#pragma db id auto
			unsigned long ItemizedObjectId_;

			unsigned long networkElementId_;

			unsigned long snmpObjectId_;	};

	#pragma db view object(ItemizedObject)
	struct ItemizedObject_stat
	{
	  #pragma db column("count(" + ItemizedObject::ItemizedObjectId_ + ")")
	  std::size_t count;
	};
}
}
}

#endif /* NEMSTA_INC_ENTITY_ITEMIZEDOBJECT_HPP_ */
