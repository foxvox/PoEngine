#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Time.h" 

namespace Po
{
	SpriteRenderer::SpriteRenderer()
	{}
	SpriteRenderer::~SpriteRenderer()
	{}

	void SpriteRenderer::Init()
	{}

	void SpriteRenderer::Update()
	{
		const float speed = 100.0f;
		const float deltaTime = float(Time::GetDeltaTime());

		Transform* tr = GetOwner()->GetComponent<Transform>();
		float x = tr->GetX(); 
		float y = tr->GetY(); 

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

		tr->SetPos(x, y); 
	}

	void SpriteRenderer::LateUpdate()
	{}

	void SpriteRenderer::Render(HDC _hdc) 
	{
		BYTE red, green, blue;

		red = rand() % 255;
		green = rand() % 255;
		blue = rand() % 255;

		HBRUSH blueBrush = CreateSolidBrush(RGB(red, green, blue));
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, blueBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(red, green, blue));
		HPEN oldPen = (HPEN)SelectObject(_hdc, redPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();  

		Rectangle(_hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

		SelectObject(_hdc, oldBrush);
		DeleteObject(blueBrush);

		SelectObject(_hdc, oldPen);
		DeleteObject(redPen);
	}
}
