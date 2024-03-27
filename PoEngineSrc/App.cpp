#include "App.h" 

namespace Po
{
	App::App()
		: hWnd(nullptr), hDC(nullptr), speed(0.0f), x(0.0f), y(0.0f)
	{
	}

	App::~App()
	{
	}

	void App::Init(HWND _hWnd)
	{
		hWnd = _hWnd;
		hDC = GetDC(hWnd);
	}

	void App::Update()
	{
		// 인자로 받은 Key가 눌렸으면 8000 return, 아니면 0 return 
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			x -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y += 0.01f;
		}
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
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, blueBrush);
		/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hDC, redPen);*/

		Rectangle(hDC, 100, 100, 200, 200);
		SelectObject(hDC, oldBrush);
		DeleteObject(blueBrush);

		/*SelectObject(hDC, oldPen);
		DeleteObject(redPen);*/
	}
}

