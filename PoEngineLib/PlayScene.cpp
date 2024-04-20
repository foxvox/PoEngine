#include "PlayScene.h" 
#include "Player.h" 
#include "Transform.h" 
#include "SpriteRenderer.h"  
#include "Input.h" 
#include "TitleScene.h" 
#include "SceneMgr.h" 
#include "Object.h" 
#include "Texture.h" 
#include "Resources.h"
#include "PlayerScript.h" 
#include "Camera.h" 
#include "Renderer.h" 
#include "Animator.h" 


namespace Bx
{
	PlayScene::PlayScene()
		: player(nullptr) 
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		//Camera 
		GameObject* cam = Instantiate<GameObject>(LayerType::NONE, Vector2(336.f, 423.f)); 
		Camera* camComp = cam->AddComponent<Camera>(); 
		camera = camComp;

		//배경	
		GameObject* bg = Instantiate<GameObject>(LayerType::BG);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		//bgsr->SetSize(Vector2(3.0f, 3.0f));		
		Texture* bgtx = Resources::Find<Texture>(L"Bubble");
		bgsr->SetTexture(bgtx);

		//플레이어
		player = Instantiate<Player>(LayerType::PLAYER);
		//SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		player->AddComponent<PlayerScript>();
		Texture* cattx = Resources::Find<Texture>(L"Cat");
		Animator* animator = player->AddComponent<Animator>(); 

		animator->CreateAnimation(L"DMove",    cattx, Vector2(0.f, 0.f),   Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f); 
		animator->CreateAnimation(L"RMove",    cattx, Vector2(0.f, 32.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		animator->CreateAnimation(L"UMove",    cattx, Vector2(0.f, 64.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		animator->CreateAnimation(L"LMove",    cattx, Vector2(0.f, 96.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		animator->CreateAnimation(L"Sit"  ,	   cattx, Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		animator->CreateAnimation(L"Grooming", cattx, Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		
		animator->PlayAnimation(L"Sit", false); 
		
		player->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));
		player->GetComponent<Transform>()->SetRot(0.f);		
		player->GetComponent<Transform>()->SetPos(Vector2(200.f, 200.f));
		//sr->SetTexture(cattx);
		
		//게임오브젝트 생성 후에 레이어와 게임오브젝트들의 Init() 호출  
		Scene::Init(); 		
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

		//Scene 전환 확인용 코드		
		/*wchar_t str[50] = L"Play Scene";
		TextOutW(_hdc, 100, 100, str, 10);*/
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		/*Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(50.f, 50.f));*/
	}
}
