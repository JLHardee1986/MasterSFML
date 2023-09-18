#ifndef __WORKER__
#define __WORKER__
#include <SFML/Graphics.hpp>
class Worker
{
protected:
	void Done()
	{
		m_done = true;
	}
	virtual void Work() = 0;
	sf::Thread m_thread;
	sf::Mutex m_mutex;
	bool m_done;
	bool m_started;
public:
	Worker()
		: m_thread(&Worker::Work, this), m_done(false), m_started(false)
	{	}

	void Begin()
	{

		if (m_done || m_started)
		{
			return;
		}
		m_started = true;
		m_thread.launch();
	}

	bool IsDone() const
	{
		return m_done;
	}

	bool HasStarted() const
	{
		return m_started;
	}
};

#endif
