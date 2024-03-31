#include "PlayScene.h" 
#include "../PoEngineSource/GameObject.h" 

namespace Po
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Init()
	{
		GameObject* obj = new GameObject(); 
		AddGameObject(obj); 
	}

	void PlayScene::Update()
	{
		Scene::Update(); 
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate(); 
	}

	void PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc); 
	}
}
