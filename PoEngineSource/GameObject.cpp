#include "GameObject.h" 

namespace Po
{
	GameObject::GameObject()
		: x(0.0f), y(0.0f)
	{}	

	GameObject::~GameObject() {}

	void GameObject::Update()
	{		
		if (Input::GetKey(KeyCode::A))
		{
			x -= 0.01f;
		}

		if (Input::GetKey(KeyCode::D))
		{
			x += 0.01f;
		}

		if (Input::GetKey(KeyCode::W))
		{
			y -= 0.01f;
		}
		if (Input::GetKey(KeyCode::S))
		{
			y += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC _hDC)
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
}
