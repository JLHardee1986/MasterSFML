#ifndef __SYSTEMMANAGER__
#define __SYSTEMMANAGER__
// NOT DONE!!!!  NEED TO MAKE THE MESSAGE HANDLER THEN UNCOMMENT THE m_messages
class Window;
class Bitmask;

using EntityId = unsigned int;
using EventId = unsigned int;

enum class System
{
	Move = 0, Collide
};

class SystemManager
{

	//MessageHandler m_messages;
	public:
		template<class T>
		void AddSystem(const System& l_system)
		{

		}

		template<class T>
		T* GetSystem(const System& l_system)
		{

		}

		void AddEvent(const EntityId& l_entity, const EventId& l_event);

		void Update(float l_dt);
		void HandleEvents();
		void Draw(Window* l_wnd, unsigned int l_elevation);

		void EntityModified(const EntityId& l_entity,
			const Bitmask& l_bits);
		void RemoveEntity(const EntityId& l_entity);

		void PurgeEntities();
		void PurgeSystems();
};

#endif
