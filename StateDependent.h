#ifndef __STATE_DEPENDENT__
#define __STATE_DEPENDENT__

enum class StateType : int;

class StateDependent
{
	StateType m_currentState;

	void SetState(const StateType& l_state)
	{
		m_currentState = l_state;
	}
	public:
		StateDependent()
			: m_currentState((StateType)0)
		{ 

		}
		virtual ~StateDependent()
		{}

		virtual void CreateState(const StateType& l_state)
		{

		}
		virtual void ChangeState(const StateType& l_state)
		{

		}
		virtual void RemoveState(const StateType& l_state)
		{

		}
};

#endif
