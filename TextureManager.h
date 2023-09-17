#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__
#include "helper.h"
#include "ResourceManager.h"

class TextureManager : public ResourceManager<TextureManager, sf::Texture>
{
	public:
		TextureManager() : ResourceManager("Textures.cfg")
		{
		
		}

		bool Load(sf::Texture* l_resource, const std::string& l_path)
		{
			return l_resource->loadFromFile(hf::GetWorkingDirectory() + l_path);
		}
};

#endif
