#ifndef __ENTITYMANAGER__
#define __ENTITYMANAGER__

#include <string>

class SystemManager;
class TextureManager;
class Bitmask;
enum class Component: int;
using EntityId = unsigned int;
class EntityManager
{
	public:
		EntityManager(SystemManager* l_sysMgr,
			TextureManager* l_textureMgr);
		~EntityManager();

		int AddEntity(const Bitmask& l_mask);
		int AddEntity(const std::string& l_entityFile);
		bool RemoveEntity(const EntityId& l_id);
		bool AddComponent(const EntityId& l_entity, const Component& l_component);

		template<class T>
		void AddComponentType(const Component& l_id)
		{

		}

		template<class T>
		T* GetComponent(const EntityId& l_entity,
			const Component& l_component)
		{

		}

		bool RemoveComponent(const EntityId& l_entity,
			const Component& l_component);
		bool HasComponent(const EntityId& l_entity,
			const Component& l_component) const;

		void Purge();

};

#endif
