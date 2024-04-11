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


namespace Bx
{
	PlayScene::PlayScene()
		: bg(nullptr) 
	{}

	PlayScene::~PlayScene()
	{}

	void PlayScene::Init()
	{
		//���ӿ�����Ʈ ����� ���� ���� Load �� �θ� ����. 

		
		bg = Instantiate<Player>(LayerType::BG/*, Vector2(100.f, 100.f)*/);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>(); 
		bg->AddComponent<PlayerScript>(); 

		Texture* bgtx = Resources::Find<Texture>(L"BG");
		sr->SetTexture(bgtx);
				
		//Texture* tx = new Texture(); 
		//tx->Load(L"C:/DevCpp/img/girl.png"); 

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
