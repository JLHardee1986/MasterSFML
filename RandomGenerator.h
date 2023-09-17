#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

class RandomGenerator
{
	std::random_device m_device;
	std::mt19937 m_engine;
	std::uniform_int_distribution<int> m_intDistribution;
	std::uniform_real_distribution<float> m_floatDistribution;
	sf::Mutex m_mutex;

	int Generate(int l_min, int l_max);
	
	float Generate(float l_min, float l_max);


public:
	RandomGenerator();

	float operator() (float l_min, float l_max);

	int operator() (int l_min, int l_max);
	
};

#endif