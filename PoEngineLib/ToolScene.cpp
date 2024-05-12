#include "ToolScene.h" 
#include "Object.h" 
#include "Tile.h" 
#include "TilemapRenderer.h" 
#include "Resources.h"
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 
#include "Input.h" 

using namespace Bx; 

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

		if (Input::GetKeyDown(KeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePos(); 

			Vector2 index; 			
			index.x = int(pos.x / TilemapRenderer::tileSpanV.x); 
			index.y = int(pos.y / TilemapRenderer::tileSpanV.y); 

			Tile* tile = Instantiate<Tile>(LayerType::TILE);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<Texture>(L"SpringFloor"));

			tile->SetPos(index.x, index.y);  
		}
	}
	
	void ToolScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);

		//그리드 그려주기 
		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(_hdc, TilemapRenderer::tileSpanV.x * i, 0, NULL); 
			LineTo(_hdc, TilemapRenderer::tileSpanV.x * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(_hdc, 0, TilemapRenderer::tileSpanV.y * i, NULL); 
			LineTo(_hdc, 1000, TilemapRenderer::tileSpanV.y * i); 
		}
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

LRESULT CALLBACK TileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		/*switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}*/
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		Texture* tx = Resources::Find<Texture>(L"SpringFloor");

		TransparentBlt(hdc,
			0, 0, tx->GetWidth(), tx->GetHeight(),
			tx->GetHDC(),
			0, 0, tx->GetWidth(), tx->GetHeight(),
			RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


