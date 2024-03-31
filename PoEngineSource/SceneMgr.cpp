#include "SceneMgr.h"

namespace Po
{
	std::map<std::wstring, Scene*> SceneMgr::scenes = {}; 
	Scene* SceneMgr::activeScene = nullptr; 

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
}