#ifndef __MESSAGEHANDLER__
#define __MESSAGEHANDLER__

#include <unordered_map>

class Observer;
class Communicator;

enum class EntityMessage : int;
struct Message;

using Subscriptions = std::unordered_map<EntityMessage, Communicator>;

class MessageHandler
{
	Subscriptions m_communicators;
	public:
		bool Subscribe(const EntityMessage& l_type,
			Observer* l_observer)
		{

		}

		bool Unsubscribe(const EntityMessage& l_type, Observer* l_observer)
		{

		}

		void Dispatch(const Message& l_msg)
		{

		}
};

#endif
