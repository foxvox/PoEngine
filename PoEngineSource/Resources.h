#pragma once
#include "Resource.h" 

namespace Bx
{
	class Resources
	{
	public: 
		template<typename T>
		static T* Find(const std::wstring& _key)
		{
			//std::map<std::wstring, Resource*>::iterator iter = resource.find(_key); 
			auto iter = resources.find(_key); 
			if (iter == resources.end())
				return nullptr; 

			return dynamic_cast<T*>(iter->second); 
		}

		template<typename T>
		static T* Load(const std::wstring& _key, const std::wstring& _path) 
		{
			T* resource = Resources::Find<T>(_key); 
			if (resource != nullptr)
				return resource; 

			resource = new T(); 
			if (FAILED(resource->Load(_path)))
			{
				assert(false); 
				//MessageBoxW(nullptr, _key.c_str() + L"Image Load Failed!", L"Error", MB_OK);
				return nullptr; 
			}

			resource->SetName(_key); 
			resource->SetPath(_path); 

			resources.insert(std::make_pair(_key, resource)); 

			return resource; 
		}
				
		static void Insert(const std::wstring& _key, Resource* _rsrc)
		{
			if (_key == L"")
				return; 

			if (_rsrc == nullptr)
				return;

			resources.insert(std::make_pair(_key, _rsrc));			
		}

		static void Release()
		{
			for (auto& iter : resources)
			{
				if (iter.second == nullptr)
					continue; 
				
				delete iter.second;
				iter.second = nullptr;								
			}
		}

	private:
		static std::map<std::wstring, Resource*> resources; 

	};
}


