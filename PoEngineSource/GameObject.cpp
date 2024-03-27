#include "GameObject.h"

Po::GameObject::GameObject()
{
}

Po::GameObject::~GameObject()
{
}

void Po::GameObject::Update()
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

void Po::GameObject::LateUpdate()
{
}

void Po::GameObject::Render(HDC _hDC)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_hDC, blueBrush);
	/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC, redPen);*/

	Rectangle(_hDC, 100 + x, 100 + y, 200 + x, 200 + y);

	SelectObject(_hDC, oldBrush);
	DeleteObject(blueBrush);

	/*SelectObject(hDC, oldPen);
	DeleteObject(redPen);*/
}
