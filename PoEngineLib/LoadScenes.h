#pragma once 
#include "../PoEngineSource/SceneMgr.h" 
#include "PlayScene.h" 

/*
#ifdef _DEBUG 
#pragma comment(lib, "../x64/Debug/PoEngineLib.lib") 
#else
#pragma comment(lib, "../x64/Release/PoEngineLib.lib")
#endif
*/

namespace Po
{
	void LoadScenes()
	{
		SceneMgr::CreateScene<PlayScene>(L"PlayScene");
		//SceneMgr::CreateScene<EndScene>(L"EndScene");
		//SceneMgr::CreateScene<TitileScene>(L"TitleScene"); 

		SceneMgr::LoadScene(L"PlayScene");
	}
}

