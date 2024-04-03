#pragma once
#include "Scene.h" 

namespace Po
{
	class SceneMgr
	{
	public: 
		template <typename T> 
		static Scene* CreateScene(const std::wstring& _name)
		{
			T* scene = new T(); 
			scene->SetName(_name); 
			scene->Init(); 

			scenes.insert(std::make_pair(_name, scene)); 

			return scene; 
		}

		static Scene* LoadScene(const std::wstring& _name)
		{
			if (activeScene)
				activeScene->OnExit();
			
			std::map<std::wstring, Scene*>::iterator iter = scenes.find(_name);

			if (iter == scenes.end())
				return nullptr; 

			activeScene = iter->second; 
			activeScene->OnEnter(); 

			return activeScene;
		}

		static void Init();		
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc); 
		
	private:
		static std::map<std::wstring, Scene*> scenes; 
		static Scene* activeScene; 
	};
}


