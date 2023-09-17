#ifndef __FONTMANAGER__
#define __FONTMANAGER__
#include "helper.h"
#include "ResourceManager.h"

class FontManager : public ResourceManager<FontManager, sf::Font>
{
public:
	FontManager() : ResourceManager("Fonts.cfg")
	{

	}

	bool Load(sf::Font* l_resource, const std::string& l_path)
	{
		return l_resource->loadFromFile(hf::GetWorkingDirectory() + l_path);
	}
};

#endif