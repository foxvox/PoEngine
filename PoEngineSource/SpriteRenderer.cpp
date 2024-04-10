#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Input.h" 
#include "Time.h" 
#include "Texture.h"

namespace Bx
{
	SpriteRenderer::SpriteRenderer()
		: Component(CompType::SR), texture(nullptr), size(Vector2::one)
	{}

	SpriteRenderer::~SpriteRenderer()
	{}

	void SpriteRenderer::Init()
	{}

	void SpriteRenderer::Update() 
	{
		const float speed = 100.f;
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
		if (texture == nullptr)
			assert(false); 

		Transform* tr = GetOwner()->GetComponent<Transform>();  
		Vector2 pos = tr->GetPos(); 

		if (texture->GetTextureType() == Texture::TextureType::Png) 
		{
			Gdiplus::Graphics graphics(_hdc);
			graphics.DrawImage(texture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y));
		}
		else if (texture->GetTextureType() == Texture::TextureType::Bmp)
		{
			//dest먼저 src나중에 
			TransparentBlt(_hdc, pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y,
				texture->GetHDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255)); 
		}

		
	}

}
