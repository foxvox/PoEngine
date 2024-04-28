#pragma once
#include "Scene.h" 

namespace Bx
{
	class SceneMgr
	{
	public: 
		template <typename T> 
		static Scene* CreateScene(const std::wstring& _name)
		{
			T* scene = new T(); 
			scene->SetName(_name); 
			activeScene = scene; 
			scene->Init(); 

			scenes.insert(std::make_pair(_name, scene)); 

			return scene; 
		}

		static Scene* LoadScene(const std::wstring& _name);	
		static Scene* GetActiveScene() { return activeScene; } 

		static void Init();		
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc); 
		static void Destroy(); 
		static void Release(); 
		
	private:
		static std::map<std::wstring, Scene*> scenes; 
		static Scene* activeScene; 
	};

	//static SceneMgr sceneMgr; 
}


