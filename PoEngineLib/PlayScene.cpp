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

namespace Bx
{
	PlayScene::PlayScene()
		: player(nullptr), cat(nullptr)
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		//Camera 
		GameObject* cam = Instantiate<GameObject>(LayerType::NONE, Vector2(336.f, 423.f)); 
		Camera* camComp = cam->AddComponent<Camera>(); 
		//camera�� Rederer.h�� ����Ǿ��ִ�. 
		camera = camComp;

		//BG	
		//GameObject* bg = Instantiate<GameObject>(LayerType::BG);
		//SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		////bgsr->SetSize(Vector2(3.0f, 3.0f));		
		//Texture* bgtx = Resources::Find<Texture>(L"Bubble");
		//bgsr->SetTexture(bgtx);

		//Player
		player = Instantiate<Player>(LayerType::PLAYER);
		PlayerScript* ps = player->AddComponent<PlayerScript>();
		BoxCollider2D* bc = player->AddComponent<BoxCollider2D>(); 
		bc->SetOffset(Vector2(-50.f, -50.f)); 

		Texture* pltx = Resources::Find<Texture>(L"Player");
		Animator* playerAnimator = player->AddComponent<Animator>(); 

		playerAnimator->CreateAnimation(L"Idle", pltx, Vector2(2000.f, 250.f), Vector2(250.f, 250.f), Vector2::zero, 1, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->CreateAnimation(L"FrontGiveWater", pltx, Vector2(0.f, 2000.f), Vector2(250.f, 250.f), Vector2::zero, 12, 0.2f);
		playerAnimator->PlayAnimation(L"Idle", false);

		//����Լ��� �۵��ϴ� ������ Ȯ���� �� �� �ִ� �ڵ���� 
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, ps); 
		
		/*player->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
		player->GetComponent<Transform>()->SetRot(0.f);	*/	
		player->GetComponent<Transform>()->SetPos(Vector2(300.f, 300.f));

		//Cat
		//cat = Instantiate<Cat>(LayerType::ANIMAL);
		////cat->SetActive(true); 
		//cat->AddComponent<CatScript>();
		//Texture* catx = Resources::Find<Texture>(L"Cat");
		//Animator* catAnimator = cat->AddComponent<Animator>();

		////ī�޶� Ÿ���� �i�ư��� ����
		////camComp->SetTarget(cat);

		//catAnimator->CreateAnimation(L"DMove",    catx, Vector2(0.f, 0.f),   Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"RMove",    catx, Vector2(0.f, 32.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"UMove",    catx, Vector2(0.f, 64.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"LMove",    catx, Vector2(0.f, 96.f),  Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"Sit",      catx, Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"Grooming", catx, Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->CreateAnimation(L"LayDown",  catx, Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		//catAnimator->PlayAnimation(L"Sit", false);
		//cat->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));		
		//cat->GetComponent<Transform>()->SetPos(Vector2(200.f, 200.f));
		
		//���ӿ�����Ʈ ���� �Ŀ� ���̾�� ���ӿ�����Ʈ���� Init() ȣ��  
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

		//Scene ��ȯ Ȯ�ο� �ڵ�		
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
