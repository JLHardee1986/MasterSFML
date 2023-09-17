#ifndef __COMMUNICATOR__
#define __COMMUNICATOR__

#include <vector>

class Observer;

struct Message;

using ObserverContainer = std::vector<Observer*>;

class Communicator
{
	ObserverContainer m_observers;

	public:
		virtual ~Communicator()
		{
			m_observers.clear();
		}
		bool AddObserver(Observer* l_observer) {

		}
		bool RemoveObserver(Observer* l_observer) {

		}
		bool HasObserver(Observer* l_observer) {

		}
		void Broadcast(const Message& l_msg)
		{

		}

};


#endif
