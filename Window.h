#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics.hpp>
class EventManager;
class Renderer;

struct EventDetails;

class Window
{
	public:
		Window(const std::string& l_title = "Window",
			const sf::Vector2u& l_size = { 640U, 480U },
			bool l_useShadows = true);
		~Window();

		void BeginDraw();
		void EndDraw();

		void Update();

		bool IsDone() const;
		bool IsFullscreen() const;
		bool IsFocused() const;

		void ToggleFullscreen(EventDetails* l_details);
		void Close(EventDetails* l_details = nullptr);

		sf::RenderWindow* GetRenderWindow();
		Renderer* GetRenderer();
		EventManager* GetEventManager();
		sf::Vector2u GetWindowSize();
		sf::FloatRect GetViewSpace();

};

#endif
