#include "PlayScene.h" 
#include "GameObject.h" 
#include "Player.h" 
#include "Transform.h" 
#include "SpriteRenderer.h"  
#include "PoMath.h" 
#include "Input.h" 
#include "TitleScene.h" 
#include "SceneMgr.h" 


namespace Po
{
	PlayScene::PlayScene()
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>(); 
			tr->SetPos(Vector2(50.0f, 50.0f));  
			tr->SetName(L"TR"); 

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR"); 
			sr->ImageLoad(L"C:/DevCpp/img/girl.png"); 

			AddGameObject(bg);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update(); 
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate(); 

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneMgr::LoadScene(L"TitleScene"); 
		}
	}

	void PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc); 
		wchar_t str[50] = L"Play Scene";
		TextOut(_hdc, 100, 100, str, 10);
	}
}
