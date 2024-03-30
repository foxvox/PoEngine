#include "App.h" 
#include "Input.h" 
#include "Time.h"  

namespace Po
{
	App::App()
		: hwnd(nullptr), hdc(nullptr), width(1600), height(900), 
		backhdc(nullptr), backBuf(nullptr), gameObjects{}  
	{}

	App::~App()
	{}

	void App::Init(HWND _hwnd)
	{
		GetWindow(_hwnd, width, height); 
		CreateBackBuf(width, height); 		

		Input::Init(); 
		Time::Init(); 	

		for (int i = 0; i < 100; i++)
		{
			GameObject* pGameObj = new GameObject();
			pGameObj->SetPos(rand() % 1600, rand() % 900); 
			gameObjects.push_back(pGameObj);			
		} 

	} 

	void App::GetWindow(HWND _hwnd, UINT _width, UINT _height)
	{
		hwnd = _hwnd;
		hdc = GetDC(hwnd);

		RECT rect = { 0, 0, _width, _height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		width = rect.right - rect.left;
		height = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, width, height, 0);
		ShowWindow(hwnd, true);
	}

	void App::CreateBackBuf(UINT _width, UINT _height)
	{
		//윈도우 해상도에 맞는 백버퍼 생성
		backBuf = CreateCompatibleBitmap(hdc, _width, _height);
		//백버퍼를 가리킬 DC생성 
		backhdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(backhdc, backBuf);
		DeleteObject(oldBitmap);
	}

	void App::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void App::Update()
	{
		Input::Update();
		Time::Update(); 
		
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update(); 
		}
	}

	void App::LateUpdate()
	{
	}

	void App::ClearBackBuf()
	{
		Rectangle(backhdc, -1, -1, width + 1, height + 1);
	}

	void App::SwapChain(HDC disp, HDC back)
	{
		//백버퍼에 있는 것을 원본 버퍼에 그려준다.
		BitBlt(disp, 0, 0, width, height, back, 0, 0, SRCCOPY);
	}

	void App::Render()
	{
		ClearBackBuf(); 
		 
		Time::Render(backhdc);

		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render(backhdc);
		}
		
		SwapChain(hdc, backhdc); 
	}

}

