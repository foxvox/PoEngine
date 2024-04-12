#include "App.h" 
#include "Input.h" 
#include "Time.h"  
#include "SceneMgr.h" 

namespace Bx
{
	App::App()
		: hwnd(nullptr), hdc(nullptr), width(672), height(846), 
		backhdc(nullptr), backBuf(nullptr) 
	{}

	App::~App()
	{}

	void App::Init(HWND _hwnd)
	{
		GetWindow(_hwnd, width, height); 
		CreateBackBuf(width, height); 		

		Input::Init(); 
		Time::Init(); 	
		SceneMgr::Init(); 
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
		//������ �ػ󵵿� �´� ����� ����
		backBuf = CreateCompatibleBitmap(hdc, _width, _height);
		//����۸� ����ų DC���� 
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
		//����ۿ� �ִ� ���� ���� ���ۿ� �׷��ش�.
		BitBlt(_disp, 0, 0, width, height, _back, 0, 0, SRCCOPY);
	}

	void App::Render()
	{
		ClearBackBuf(); 
		 
		Time::Render(backhdc);
		SceneMgr::Render(backhdc);
		
		SwapChain(hdc, backhdc); 
	}

}

