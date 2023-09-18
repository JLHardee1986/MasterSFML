#ifndef __STATEMANAGER__
#define __STATEMANAGER__

#include <SFML/Graphics.hpp>

#include <list>

class GameContext;
class StateDependent;
class State_Loading;
enum class StateType : int;

using StateDependents = std::list<StateDependent>;

class StateManager
{
	State_Loading* m_loading;
	StateDependents m_dependents;
	public:
		StateManager(GameContext* l_context);
		~StateManager();
		void Update(const sf::Time& l_time);
		void Draw();
		void ProcessRequests();
		GameContext* GetContext();
		bool HasState(const StateType& l_type) const;
		StateType GetNextToLast() const;
		void SwitchTo(const StateType& l_type);
		void Remove(const StateType& l_type);
		template<class T>
		T* GetState(const StateType& l_type)
		{

		}
		template<class T>
		void RegisterState(const StateType& l_type)
		{

		}
		void AddDependent(StateDependent* l_dependent);
		void RemoveDependent(StateDependent* l_dependent);

};

#endif
