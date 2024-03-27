#include "App.h" 

Po::App::App()
	: hWnd(nullptr), hDC(nullptr), speed(0.0f), x(0.0f), y(0.0f)
{
}

Po::App::~App()
{
}

void Po::App::Init(HWND _hWnd)
{
	hWnd = _hWnd;
	hDC = GetDC(hWnd);
}

void Po::App::Update()
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

void Po::App::LateUpdate()
{

}

void Po::App::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Po::App::Render()
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, blueBrush);
	/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC, redPen);*/

	Rectangle(hDC, 100 + int(x), 100 + int(y), 200 + int(x), 200 + int(y));
		
	SelectObject(hDC, oldBrush);
	DeleteObject(blueBrush);

	/*SelectObject(hDC, oldPen);
	DeleteObject(redPen);*/
}


