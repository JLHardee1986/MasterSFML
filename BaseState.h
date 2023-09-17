#ifndef __BASESTATE__
#define __BASESTATE__

#include <SFML/Graphics.hpp>

class StateManager;

enum class StateType : int
{
	Splash = 1, Title, Game, Loading
};

class BaseState
{
	friend class StateManager;
	
	protected:
		StateManager* m_stateMgr;
		bool m_transparent;
		bool m_transcendent;
		sf::View m_view;

	public:
		BaseState(StateManager* l_stateManager)
			: m_stateMgr(l_stateManager), m_transparent(false),
			m_transcendent(false)
		{

		}
		virtual ~BaseState()
		{}

		virtual void OnCreate() = 0;
		virtual void OnDestroy() = 0;

		virtual void Activate() = 0;
		virtual void Deactivate() = 0;

		virtual void Update(const sf::Time& l_time) = 0;
		virtual void Draw() = 0;

		sf::View& GetView()
		{
			return m_view;
		}
		StateManager* GetStateManager()
		{
			return m_stateMgr;
		}
};

#endif
