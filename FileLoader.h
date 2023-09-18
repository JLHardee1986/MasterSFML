#ifndef __FILELOADER__
#define __FILELOADER__

#include "Worker.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using LoaderPaths = std::vector<std::pair<std::string, size_t> >;

class FileLoader : public Worker
{
protected:
	virtual bool ProcessLine(std::stringstream& l_stream) = 0;
	virtual void ResetForNextFile() {}
	void Work()
	{
		CountFileLines();
		if (!m_totalLines)
		{
			Done();
			return;
		}
		for (auto& path : m_files)
		{
			ResetForNextFile();
			std::ifstream file(path.first);
			std::string line;
			std::string name;
			auto linesLeft = path.second;
			while (std::getline(file, line))
			{
				{
					sf::Lock lock(m_mutex);
					++m_currentLine;
					--linesLeft;
				}
				if (line[0] == '|') { continue; }
				std::stringstream keystream(line);
				if (!ProcessLine(keystream))
				{
					std::cout << "File loader terminated due to an internal error." << std::endl;
					{
						sf::Lock lock(m_mutex);

						m_currentLine += linesLeft;
					}
					break;
				}
			}
		file.close();
	}
	Done();
}
	void CountFileLines()
	{
		m_totalLines = 0;
		m_currentLine = 0;
		for (auto path = m_files.begin(); path != m_files.end();)
		{
			if (path->first.empty())
			{
				m_files.erase(path);
				std::cout << "Empty File \n";
				continue;
			}
			std::ifstream file(path->first);
			if (!file.is_open())
			{
				std::cerr << "Failed to load file: " << path->first << std::endl;
				m_files.erase(path);
				continue;
			}
			file.unsetf(std::ios_base::skipws);
			{
				sf::Lock lock(m_mutex);
				path->second = static_cast<size_t>(std::count(
					std::istreambuf_iterator<char>(file),
					std::istreambuf_iterator<char>(), '\n'));
				m_totalLines += path->second;
			}
			++path;
			file.close();
		}
	}

	LoaderPaths m_files;
	size_t m_totalLines;
	size_t m_currentLine;

	public:
		FileLoader()
			: m_totalLines(0), m_currentLine(0) {}
		void AddFile(const std::string& l_file)
		{
			m_files.emplace_back(l_file, 0);
		}
		virtual void SaveToFile(const std::string& l_file)
		{

		}

		size_t GetTotalLines()
		{
			sf::Lock lock(m_mutex);
			return m_totalLines;
		}

		size_t GetCurrentLine()
		{
			sf::Lock lock(m_mutex);
			return m_currentLine;
		}

};

#endif
