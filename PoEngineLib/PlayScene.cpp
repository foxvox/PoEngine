#include "PlayScene.h" 
#include "../PoEngineSource/GameObject.h" 
#include "../PoEngineSource/Player.h" 
#include "../PoEngineSource/Transform.h" 
#include "../PoEngineSource/SpriteRenderer.h"  


namespace Po
{
	PlayScene::PlayScene()
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		{
			Player* p = new Player();
			Transform* tr = p->AddComponent<Transform>(); 
			tr->SetPos(300, 450); 
			tr->SetName(L"TR"); 

			SpriteRenderer* sr = p->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");  

			AddGameObject(p);

		}

		{
			Player* p = new Player();
			Transform* tr = p->AddComponent<Transform>();
			tr->SetPos(100, 650);
			tr->SetName(L"TR");

			SpriteRenderer* sr = p->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(p);
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
