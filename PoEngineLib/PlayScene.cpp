#include "PlayScene.h" 
#include "Player.h" 
#include "Transform.h" 
#include "SpriteRenderer.h"  
#include "Input.h" 
#include "TitleScene.h" 
#include "SceneMgr.h" 


namespace Po
{
	PlayScene::PlayScene()
		: bg(nullptr) 
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		{
			bg = new Player();
			Transform* tr = bg->AddComponent<Transform>(); 
			tr->SetPos(Vector2(50.f, 50.f));  
			tr->SetName(L"TR"); 

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR"); 
			sr->ImageLoad(L"C:/DevCpp/img/girl.png"); 

			AddGameObject(bg, LayerType::BG); 
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
		TextOutW(_hdc, 100, 100, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(50.f, 50.f));
	}
}
