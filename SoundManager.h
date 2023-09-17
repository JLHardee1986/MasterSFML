#ifndef __SOUNDMANAGER__
#define __SOUNDMANAGER__
#include "helper.h"
#include "ResourceManager.h"
#include <SFML/Audio.hpp>

class SoundManager : public ResourceManager<SoundManager, sf::SoundBuffer>
{
public:
	SoundManager() : ResourceManager("Sounds.cfg")
	{

	}

	bool Load(sf::SoundBuffer* l_resource, const std::string& l_path)
	{
		return l_resource->loadFromFile(hf::GetWorkingDirectory() + l_path);
	}
};

#endif