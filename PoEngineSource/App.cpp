#include "App.h" 
#include "Input.h" 
#include "BxTime.h"  
#include "SceneMgr.h" 
#include "Resources.h" 

namespace Bx
{
	App::App()
		: hwnd(nullptr), hdc(nullptr), width(672), height(846), 
		backhdc(nullptr), backBuf(nullptr) 
	{
		BxTime::Init();
		Input::Init();
		SceneMgr::Init();
	}

	App::~App()
	{}

	void App::Init(HWND _hwnd)
	{
		GetWindow(_hwnd, width, height); 
		CreateBackBuf(width, height); 		
	} 

	void App::GetWindow(HWND _hwnd, UINT _width, UINT _height)
	{
		hwnd = _hwnd;
		hdc = GetDC(hwnd);

		RECT rect = { 0, 0, (LONG)_width, (LONG)_height };
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

		Destroy(); 
	}

	void App::Update()
	{
		Input::Update();
		BxTime::Update();
		SceneMgr::Update(); 
	}

	void App::LateUpdate()
	{
		SceneMgr::LateUpdate();
	}

	void App::ClearBackBuf()
	{
		Rectangle(backhdc, -1, -1, width + 1, height + 1);
	}

	void App::SwapChain(HDC _disp, HDC _back)
	{
		//백버퍼에 있는 것을 원본버퍼에 그려준다.
		BitBlt(_disp, 0, 0, width, height, _back, 0, 0, SRCCOPY);
	}

	void App::Render()
	{
		ClearBackBuf(); 
		 
		BxTime::Render(backhdc);
		SceneMgr::Render(backhdc);
		
		//백버퍼와 원본버퍼를 Swap
		SwapChain(hdc, backhdc); 
	}

	void App::Release()
	{
		SceneMgr::Release(); 
		Resources::Release(); 
	}

	void App::Destroy()
	{
		SceneMgr::Destroy();
	}
}

