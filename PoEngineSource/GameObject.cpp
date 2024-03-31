#include "GameObject.h" 
#include "Time.h" 

namespace Po
{
	GameObject::GameObject()
		: x(0.0f), y(0.0f)
	{}	

	GameObject::~GameObject() {}

	void GameObject::Update()
	{
		const float speed = 100.0f;
		const float deltaTime = float(Time::GetDeltaTime());

		if (Input::GetKey(KeyCode::Left))
		{
			x -= speed * deltaTime;
		}

		if (Input::GetKey(KeyCode::Right))
		{
			x += speed * deltaTime;
		}

		if (Input::GetKey(KeyCode::Up))
		{
			y -= speed * deltaTime;
		}
		if (Input::GetKey(KeyCode::Down))
		{
			y += speed * deltaTime;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC _hdc)
	{
		BYTE red, green, blue; 

		red = rand() % 255; 
		green = rand() % 255; 
		blue = rand() % 255; 

		HBRUSH blueBrush = CreateSolidBrush(RGB(red, green, blue));
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, blueBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(red, green, blue));
		HPEN oldPen = (HPEN)SelectObject(_hdc, redPen);

		Rectangle(_hdc, x, y, x + 100, y + 100);

		SelectObject(_hdc, oldBrush);
		DeleteObject(blueBrush);

		SelectObject(_hdc, oldPen);
		DeleteObject(redPen); 
	}
}
