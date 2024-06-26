#include "TitleScene.h" 
#include "SceneMgr.h" 
#include "Input.h" 

namespace Bx
{
	TitleScene::TitleScene()
	{}

	TitleScene::~TitleScene()
	{}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneMgr::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
		wchar_t str[50] = L"Title Scene";
		TextOutW(_hdc, 100, 100, str, 11);
	}
}

