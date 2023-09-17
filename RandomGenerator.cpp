#include "RandomGenerator.h"

int RandomGenerator::Generate(int l_min, int l_max)
{
	sf::Lock lock(m_mutex);
	if (l_min > l_max) { std::swap(l_min, l_max); }
	if (l_min != m_intDistribution.min() ||
		l_max != m_intDistribution.max())
	{
		m_intDistribution = std::uniform_int_distribution<int>(l_min, l_max);
	}
	return m_intDistribution(m_engine);
}

float RandomGenerator::Generate(float l_min, float l_max)
{
	sf::Lock lock(m_mutex);
	if (l_min > l_max) { std::swap(l_min, l_max); }
	if (l_min != m_floatDistribution.min() ||
		l_max != m_floatDistribution.max())
	{
		m_floatDistribution = std::uniform_real_distribution<float>(l_min, l_max);
	}
	return m_floatDistribution(m_engine);
}

RandomGenerator::RandomGenerator() : m_engine(m_device())
{

}
float RandomGenerator::operator() (float l_min, float l_max)
{
	return Generate(l_min, l_max);
}
int RandomGenerator::operator() (int l_min, int l_max)
{
	return Generate(l_min, l_max);
}