#include "ToolScene.h" 
#include "Object.h" 
#include "Tile.h" 
#include "TilemapRenderer.h" 
#include "Resources.h"
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 

namespace Bx
{
	ToolScene::ToolScene()
	{}

	ToolScene::~ToolScene()
	{}
	
	void ToolScene::Initialize()
	{
		GameObject* cam = Instantiate<GameObject>(LayerType::NONE, Vector2(336.f, 423.f));
		Camera* camComp = cam->AddComponent<Camera>();
		//camera는 Rederer.h에 선언되어있다. 
		camera = camComp;

		Tile* tile = Instantiate<Tile>(LayerType::TILE); 
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>(); 
		tmr->SetTexture(Resources::Find<Texture>(L"SpringFloor")); 

		Scene::Initialize(); 
	}
	
	void ToolScene::Update()
	{
		Scene::Update();
	}
	
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void ToolScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
	
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}
