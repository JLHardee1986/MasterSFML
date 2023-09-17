#ifndef __OBSERVER__
#define __OBSERVER__

#include <string>
class Observer;
struct Message
{
	std::string msg;
	Observer* observer;
};

class Observer
{


	public:
		virtual ~Observer()
		{

		}

		virtual void Notify(const Message& l_message) = 0;
};

#endif
