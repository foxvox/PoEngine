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
		for (int i = 0; i < 7; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPos(rand() % 1600, rand() % 900); 
			AddGameObject(obj);
		}
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
