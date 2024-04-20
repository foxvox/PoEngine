#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Input.h" 
#include "Time.h" 
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 

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
		/* PlayerScript에서 처리하기로 함 deprecated 
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
		*/
	}

	void SpriteRenderer::LateUpdate() 
	{}

	void SpriteRenderer::Render(HDC _hdc) 
	{
		if (texture == nullptr)
			assert(false); 

		Transform* tr = GetOwner()->GetComponent<Transform>();  		
		Vector2 pos = tr->GetPos();
		float rot = tr->GetRot();
		Vector2 scale = tr->GetScale();
		
		//Vector2 camPos = camera->CalPos(pos); 
		//캠위치를 게임오브젝트 위치에 할당, 카메라 오작동시 할당 취소
		//pos = camPos; 

		if (texture->GetTextureType() == Texture::TextureType::PNG) 
		{
			//내가 원하는 픽셀을 투명화 시킬 때 
			Gdiplus::ImageAttributes imgAttrib{};
			//투명화 시킬 픽셀의 색 범위
			imgAttrib.SetColorKey(Gdiplus::Color(240, 240, 240), Gdiplus::Color(255, 255, 255));

			//size.x and size.y means scaling
			Gdiplus::Graphics graphics(_hdc);

			//회전 
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(texture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, 
					texture->GetWidth() * size.x * scale.x, texture->GetHeight() * size.y * scale.y), 
				0, 0, texture->GetWidth(), texture->GetHeight(),
				Gdiplus::UnitPixel, &imgAttrib);
		}
		else if (texture->GetTextureType() == Texture::TextureType::BMP) 
		{
			//dest먼저 src나중 순서로 사용됨  
			TransparentBlt(_hdc, pos.x, pos.y, 
				texture->GetWidth() * size.x * scale.x, texture->GetHeight() * size.y * scale.y, 
				texture->GetHDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255)); 
		}		
	}
}
