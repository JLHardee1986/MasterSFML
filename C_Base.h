#ifndef __C_BASE__
#define __C_BASE__

#include <sstream>

enum class Component : int
{
	Moveable = 0, Controllable, Collidable, Personable
};

class C_Base
{
protected:
	Component m_type;
public:
	C_Base(const Component& l_type)
		: m_type(l_type) {}
	virtual ~C_Base()
	{}

	Component GetType() const { return m_type; }

	friend std::stringstream& operator>>(std::stringstream& l_stream, C_Base& b)
	{
		b.ReadIn(l_stream);
		return l_stream;
	}
	
	virtual void ReadIn(std::stringstream& l_stream) = 0;
};

#endif
