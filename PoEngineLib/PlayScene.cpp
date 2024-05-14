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
		//camera는 Rederer.h에 선언되어있다. 
		mainCam = camComp;

		//Player
		player = Instantiate<Player>(LayerType::PLAYER);
		DontDestroyOnLoad(player); 

		PlayerScript* ps = player->AddComponent<PlayerScript>();
		//BoxCollider2D* pbc = player->AddComponent<BoxCollider2D>(); 
		//pbc->SetOffset(Vector2(-50.f, -50.f)); 
		CircleCollider2D* pcc = player->AddComponent<CircleCollider2D>();
		pcc->SetOffset(Vector2(-50.f, -50.f));

		Texture* pltx = Resources::Find<Texture>(L"Player");
		Animator* playerAnimator = player->AddComponent<Animator>(); 
		playerAnimator->CreateAnimation(L"Idle", pltx, Vector2(2000.f, 250.f), Vector2(250.f, 250.f), Vector2::zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", pltx, Vector2(0.f, 2000.f), Vector2(250.f, 250.f), Vector2::zero, 12, 0.2f);
		playerAnimator->PlayAnimation(L"Idle", false);

		player->AddComponent<Rigidbody>();

		//멤버함수가 작동하는 원리를 확실히 알 수 있는 코드라인 
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, ps);		
		player->GetComponent<Transform>()->SetPos(Vector2(300.f, 300.f));

		//Cat관련
		cat = Instantiate<Cat>(LayerType::ANIMAL);		 
		cat->AddComponent<CatScript>();
		Texture* catx = Resources::Find<Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		//BoxCollider2D* cbc = cat->AddComponent<BoxCollider2D>(); 
		//cbc->SetOffset(Vector2(-50.f, -50.f)); 
		CircleCollider2D* ccc = cat->AddComponent<CircleCollider2D>();
		ccc->SetOffset(Vector2(-50.f, -50.f));

		//카메라가 타겟을 쫒아가게 설정
		//camComp->SetTarget(cat);

		/*catAnimator->CreateAnimation(L"DMove",    catx, Vector2(0.f, 0.f),   Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"RMove",    catx, Vector2(0.f, 32.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"UMove",    catx, Vector2(0.f, 64.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LMove",    catx, Vector2(0.f, 96.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"Sit",      catx, Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"Grooming", catx, Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LayDown",  catx, Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->PlayAnimation(L"Sit", false);*/ 

		catAnimator->CreateAniByFolder(L"MushroomIdle", L"../Resources/Mushroom/", Vector2::zero, 0.1f); 
		catAnimator->PlayAnimation(L"MushroomIdle", true);  

		cat->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
		cat->GetComponent<Transform>()->SetPos(Vector2(100.f, 100.f));		
		
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
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit(); 		
	}
}
