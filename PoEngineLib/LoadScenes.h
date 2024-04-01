#pragma once 
#include "SceneMgr.h" 
#include "PlayScene.h" 
#include "TitleScene.h" 

namespace Po
{
	void LoadScenes()
	{
		SceneMgr::CreateScene<TitleScene>(L"TitleScene");
		SceneMgr::CreateScene<PlayScene>(L"PlayScene");
		//SceneMgr::CreateScene<EndScene>(L"EndScene");		 

		SceneMgr::LoadScene(L"PlayScene");
	}
}

