#include "App.h" 
#include "Input.h" 
#include "Time.h" 

namespace Po
{
	App::App()
		: hWnd(nullptr), hDC(nullptr), width(1920), height(1080) 
	{
	}

	App::~App()
	{
	}

	void App::Init(HWND _hWnd)
	{
		hWnd = _hWnd;
		hDC = GetDC(hWnd);

		RECT rect = { 0, 0, width, height }; 
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		width = rect.right - rect.left; 
		height = rect.bottom - rect.top; 
		
		SetWindowPos(hWnd, nullptr, 0, 0, width, height, 0);  
		ShowWindow(hWnd, true); 

		//윈도우 해상도에 맞는 백버퍼 생성
		backBuf = CreateCompatibleBitmap(hDC, width, height); 
		//백버퍼를 가리킬 DC생성 
		backHDC = CreateCompatibleDC(hDC); 
		HBITMAP oldBitmap = (HBITMAP)SelectObject(backHDC, backBuf); 
		DeleteObject(oldBitmap); 

		player.SetPos(0.0f, 0.0f);

		Input::Init(); 
		Time::Init(); 		
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
		player.Update();		
	}

	void App::LateUpdate()
	{
	}

	void App::Render()
	{
		Rectangle(backHDC, 0, 0, width, height); 
		Time::Render(backHDC);
		player.Render(backHDC);

		BitBlt(hDC, 0, 0, width, height, backHDC, 0, 0, SRCCOPY); 
	} 
}

