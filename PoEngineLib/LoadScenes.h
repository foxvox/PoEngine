#pragma once 
#include "SceneMgr.h" 
#include "PlayScene.h" 
#include "TitleScene.h" 
#include "ToolScene.h" 

namespace Bx
{
	void LoadScenes()
	{
		SceneMgr::CreateScene<TitleScene>(L"TitleScene"); 
		SceneMgr::CreateScene<PlayScene>(L"PlayScene"); 
		//SceneMgr::CreateScene<ToolScene>(L"ToolScene"); 
		SceneMgr::LoadScene(L"PlayScene");
	}
}

