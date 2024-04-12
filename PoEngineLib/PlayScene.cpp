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
		GameObject* cam = Instantiate<GameObject>(LayerType::None, Vector2(336.f, 423.f)); 
		Camera* camComp = cam->AddComponent<Camera>(); 
		camera = camComp; 
		cam->AddComponent<PlayerScript>(); 

		GameObject* bg = Instantiate<GameObject>(LayerType::BG);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(3.0f, 3.0f));
		bg->AddComponent<PlayerScript>();

		Texture* bgtx = Resources::Find<Texture>(L"Map");
		bgsr->SetTexture(bgtx);

		player = Instantiate<Player>(LayerType::PLAYER);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		bg->AddComponent<PlayerScript>();

		Texture* pmtx = Resources::Find<Texture>(L"Pacman");
		sr->SetTexture(pmtx);
		
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
		wchar_t str[50] = L"Play Scene";
		TextOutW(_hdc, 100, 100, str, 10);
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
