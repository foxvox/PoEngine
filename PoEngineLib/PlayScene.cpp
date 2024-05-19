#include "PlayScene.h" 
#include "Transform.h" 
#include "SpriteRenderer.h"  
#include "Input.h" 
#include "TitleScene.h" 
#include "SceneMgr.h" 
#include "Object.h" 
#include "Texture.h" 
#include "Resources.h"
#include "Player.h" 
#include "PlayerScript.h" 
#include "Camera.h" 
#include "Renderer.h" 
#include "Animator.h" 
#include "Cat.h"
#include "CatScript.h" 
#include "BoxCollider2D.h" 
#include "CircleCollider2D.h" 
#include "CollisionMgr.h" 
#include "DontDestroyOnLoad.h" 
#include "Tile.h" 
#include "TilemapRenderer.h" 
#include "Rigidbody.h" 
#include "Floor.h" 
#include "FloorScript.h" 

namespace Bx
{
	PlayScene::PlayScene()
		: player(nullptr), cat(nullptr)
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Initialize()
	{
		CollisionMgr::LayerCollisionCheck(LayerType::PLAYER, LayerType::ANIMAL, true);

		//Camera 
		GameObject* cam = Instantiate<GameObject>(LayerType::NONE, Vector2(336.f, 423.f)); 
		Camera* camComp = cam->AddComponent<Camera>(); 
		//mainCam은 Rederer.h에 선언되어있다. 
		mainCam = camComp;

		//Player
		player = Instantiate<Player>(LayerType::PLAYER);
		DontDestroyOnLoad(player); 


		PlayerScript* ps = player->AddComponent<PlayerScript>();
		BoxCollider2D* pbc = player->AddComponent<BoxCollider2D>(); 
		pbc->SetOffset(Vector2(-50.f, -50.f)); 
		//CircleCollider2D* pcc = player->AddComponent<CircleCollider2D>();
		//pcc->SetOffset(Vector2(-50.f, -50.f));

		Texture* pltx = Resources::Find<Texture>(L"Player");
		Animator* playerAnimator = player->AddComponent<Animator>(); 
		playerAnimator->CreateAnimation(L"Idle", pltx, Vector2(2000.f, 250.f), Vector2(250.f, 250.f), Vector2::zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", pltx, Vector2(0.f, 2000.f), Vector2(250.f, 250.f), Vector2::zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, ps);
		player->GetComponent<Transform>()->SetPos(Vector2(300.0f, 250.0f));

		player->AddComponent<Rigidbody>();
		Floor* floor = Instantiate<Floor>(LayerType::FLOOR, Vector2(150.f, 600.f)); 
		BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>(); 
		floorCol->SetSpan(Vector2(3.f, 1.f)); 
		floor->AddComponent<FloorScript>(); 

		//카메라가 타겟을 쫒아가게 설정
		//camComp->SetTarget(player);
	
		
		//게임오브젝트 생성 후에 레이어와 게임오브젝트들의 Initialize() 호출  
		Scene::Initialize(); 		
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
		Scene::OnEnter(); 

		CollisionMgr::LayerCollisionCheck(LayerType::PLAYER, LayerType::ANIMAL, true); 
		CollisionMgr::LayerCollisionCheck(LayerType::PLAYER, LayerType::FLOOR, true);

	}

	void PlayScene::OnExit()
	{
		Scene::OnExit(); 		
	}
}
