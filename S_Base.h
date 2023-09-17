#ifndef __S_BASE__
#define __S_BASE__

#include "Observer.h"
class Bitmask;
class SystemManager;
enum class System : int;
enum class EntityEvent : int;
using EntityId = unsigned int;

class S_Base : public Observer
{
	protected:

	public:
		S_Base(const System& l_id, SystemManager* l_systemMgr);
		virtual ~S_Base();

		bool AddEntity(const EntityId& l_entity);
		bool HasEntity(const EntityId& l_entity) const;
		bool RemoveEntity(const EntityId& l_entity);

		System GetId() const;

		bool FitsRequirements(const Bitmask& l_bits) const;

		void Purge();

		virtual void Update(float l_dt) = 0;
		virtual void HandleEvent(const EntityId& l_entity,
			const EntityEvent& l_event) = 0;
};

#endif
