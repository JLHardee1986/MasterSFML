#ifndef __RESOURCEMANAGER__
#define __RESOURCEMANAGER__
#include <SFML/Graphics.hpp>
#include <string>

template<typename Derived, typename T>
class ResourceManager
{
	protected:
		bool Load(T* l_resource, const std::string& path)
		{
			return static_cast<Derived*>(this)->Load(l_resource, l_path);
		}
	public:
		ResourceManager(const std::string& l_pathFile)
		{
			LoadPaths(l_pathsFile);
		}
		virtual ~ResourceManager()
		{

		}
		T* GetResource(const std::string& l_id)
		{
			return T * a();
		}
		std::string GetPath(const std::string& l_id)
		{
			return "NULL";
		}
		bool AcquireResource(const std::string& l_id)
		{
			return false;
		}
		bool ReleaseResource(const std::string& l_id)
		{
		}
		void PurgeResources()
		{
		}

};

#endif
