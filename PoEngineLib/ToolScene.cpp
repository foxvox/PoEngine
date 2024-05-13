#include "ToolScene.h" 
#include "Object.h" 
#include "Tile.h" 
#include "TilemapRenderer.h" 
#include "Resources.h"
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 
#include "Input.h" 
#include "CameraScript.h" 

using namespace Bx; 

namespace Bx
{
	ToolScene::ToolScene()
	{}

	ToolScene::~ToolScene()
	{}
	
	void ToolScene::Initialize()
	{
		GameObject* cam = Instantiate<GameObject>(LayerType::NONE, Vector2(344.f, 442.f));
		Camera* camComp = cam->AddComponent<Camera>();	
		cam->AddComponent<CameraScript>();
		mainCam = camComp;

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
			pos = mainCam->CalTilePos(pos);

			if (pos.x >= 0.0f && pos.y >= 0.0f)
			{
				Vector2 index;
				index.x = int(pos.x / TilemapRenderer::tileSpanV.x);
				index.y = int(pos.y / TilemapRenderer::tileSpanV.y);

				Tile* tile = Instantiate<Tile>(LayerType::TILE);
				TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
				tmr->SetTexture(Resources::Find<Texture>(L"SpringFloor"));
				tmr->SetIndex(TilemapRenderer::selectedIndex); 

				tile->SetIndexPos(index.x, index.y);
				tiles.push_back(tile); 
			}			 
		}

		if (Input::GetKeyDown(KeyCode::S))
		{
			Save(); 
		}

		if (Input::GetKeyDown(KeyCode::L))
		{
			Load();
		}
	}
	
	void ToolScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = mainCam->CalPos(Vector2(i * TilemapRenderer::tileSpanV.x, 0.f));

			MoveToEx(_hdc, pos.x, 0, NULL); 
			LineTo(_hdc, pos.x, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = mainCam->CalPos(Vector2(0.f, i * TilemapRenderer::tileSpanV.y)); 

			MoveToEx(_hdc, 0, pos.y, NULL); 
			LineTo(_hdc, 1000, pos.y); 
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

	void ToolScene::Save()
	{
		OPENFILENAME ofn{}; 
		wchar_t szFilePath[256]{}; 

		ZeroMemory(&ofn, sizeof(ofn)); 
		ofn.lStructSize = sizeof(ofn); 
		ofn.hwndOwner = NULL; 
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0'; 
		ofn.nMaxFile = 256; 
		ofn.lpstrFilter = L"Tile\0*.tile\0"; 
		ofn.nFilterIndex = 1; 
		ofn.lpstrFileTitle = NULL; 
		ofn.nMaxFileTitle = 0; 
		ofn.lpstrInitialDir = NULL; 
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; 

		if (false == GetSaveFileName(&ofn))
			return; 

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");		

		for (Tile* tile : tiles)
		{
			TilemapRenderer* tmr = tile->GetComponent<TilemapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPos();

			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn{};

		wchar_t szFilePath[256]{};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = Instantiate<Tile>(LayerType::TILE, Vector2(float(posX), float(posY)));
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(float(idxX), float(idxY)));

			tiles.push_back(tile);
		}

		fclose(pFile);
	}
}

LRESULT CALLBACK TileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos{};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		Vector2 index;

		index.x = int(mousePos.x / TilemapRenderer::originTileSpan.x);
		index.y = int(mousePos.y / TilemapRenderer::originTileSpan.y);

		TilemapRenderer::selectedIndex = index;	
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


