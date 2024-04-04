#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Input.h" 
#include "Time.h" 

namespace Po
{
	SpriteRenderer::SpriteRenderer() 
		: image(nullptr), width(0), height(0) 
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
		float x = tr->GetPos().x; 
		float y = tr->GetPos().y; 

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

		tr->SetPos(Vector2(x, y));  
	}

	void SpriteRenderer::LateUpdate()
	{}

	void SpriteRenderer::Render(HDC _hdc) 
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();  
		Vector2 pos = tr->GetPos(); 

		Gdiplus::Graphics graphics(_hdc); 
		graphics.DrawImage(image, Gdiplus::Rect(pos.x, pos.y, width, height)); 
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		image = Gdiplus::Image::FromFile(path.c_str()); 
		width = image->GetWidth(); 
		height = image->GetHeight(); 
	}

}
