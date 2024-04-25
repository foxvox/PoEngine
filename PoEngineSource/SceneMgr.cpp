#include "SceneMgr.h"

namespace Bx
{
	std::map<std::wstring, Scene*> SceneMgr::scenes{}; 
	Scene* SceneMgr::activeScene = nullptr; 

	Scene* SceneMgr::LoadScene(const std::wstring& _name)
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

	void SceneMgr::Init()
	{		
	}

	void SceneMgr::Update()
	{
		activeScene->Update(); 
	}

	void SceneMgr::LateUpdate()
	{
		activeScene->LateUpdate(); 
	}

	void SceneMgr::Render(HDC _hdc)
	{
		activeScene->Render(_hdc); 
	}

	void SceneMgr::Release()
	{
		//static std::map<std::wstring, Scene*> scenes; 
		for (auto& iter : scenes)
		{
			if (iter.second == nullptr)
				continue; 

			delete iter.second; 
			iter.second = nullptr;
		}
	}
}