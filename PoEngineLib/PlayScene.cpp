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

		//���	
		GameObject* bg = Instantiate<GameObject>(LayerType::BG);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		//bgsr->SetSize(Vector2(3.0f, 3.0f));		
		Texture* bgtx = Resources::Find<Texture>(L"Bubble");
		bgsr->SetTexture(bgtx);

		//�÷��̾�
		player = Instantiate<Player>(LayerType::PLAYER);
		//SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		player->AddComponent<PlayerScript>();
		Texture* cattx = Resources::Find<Texture>(L"Effect");
		Animator* animator = player->AddComponent<Animator>(); 
		animator->CreateAnimation(L"CatFrontMove", cattx, Vector2(0.f, 0.f), Vector2(386.f, 246.f), Vector2::zero, 8, 0.1f); 
		animator->PlayAnimation(L"CatFrontMove", true); 
		
		player->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
		player->GetComponent<Transform>()->SetRot(30.f);		
		player->GetComponent<Transform>()->SetPos(Vector2(300.f, 200.f));
		//sr->SetTexture(cattx);
		
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
