#include "App.h" 

namespace Po
{
	App::App()
		: hWnd(nullptr), hDC(nullptr)
	{
	}

	App::~App()
	{
	}

	void App::Init(HWND _hWnd)
	{
		hWnd = _hWnd;
		hDC = GetDC(hWnd);
		player.SetPos(0.0f, 0.0f);
	}

	void App::Update()
	{
		player.Update();
	}

	void App::LateUpdate()
	{
	}

	void App::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void App::Render()
	{
		player.Render(hDC);
	} 
}

