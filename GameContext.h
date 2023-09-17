#ifndef __GAMECONTEXT__
#define __GAMECONTEXT__

class Window;
class EventManager;
class TextureManager;
class FontManager;

struct GameContext
{
	Window* m_wnd;
	EventManager* m_eventManager;
	TextureManager* m_textureManager;
	FontManager* m_fontManager;

	GameContext() :
		m_wnd(nullptr), m_eventManager(nullptr), m_textureManager(nullptr), m_fontManager(nullptr)
	{

	}
};

#endif
