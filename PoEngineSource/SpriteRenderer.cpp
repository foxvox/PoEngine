#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Input.h" 
#include "BxTime.h" 
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 

namespace Bx
{
	SpriteRenderer::SpriteRenderer()
		: Component(CompType::SR), texture(nullptr), span(Vector2::One)
	{}

	SpriteRenderer::~SpriteRenderer()
	{}

	void SpriteRenderer::Initialize()
	{}

	void SpriteRenderer::Update() 
	{
		/* PlayerScript에서 처리하기로 함 deprecated 
		const float speed = 100.f;
		const float deltaTime = Time::DeltaTime();

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
		
		Vector2 camPos = mainCam->CalPos(pos);
		pos = camPos; 

		if (texture->GetTextureType() == Texture::TextureType::BMP) 
		{			
			if (texture->IsAlpha())
			{
				//알파블렌드를 쓰려면 해당 이미지에 알파채널이 있어야 한다. 
				BLENDFUNCTION func{};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;  //0=>transparent, 255=>Opaque 				

				AlphaBlend(_hdc, int(pos.x), int(pos.y),
					int(texture->GetWidth() * span.x * scale.x), int(texture->GetHeight() * span.y * scale.y),
					texture->GetHDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), func);
			}
			else 
			{
				//dest먼저 src나중 순서로 사용됨  
				TransparentBlt(_hdc, int(pos.x), int(pos.y),
					int(texture->GetWidth() * span.x * scale.x), int(texture->GetHeight() * span.y * scale.y),
					texture->GetHDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255));
			}
		}
		else if (texture->GetTextureType() == Texture::TextureType::PNG)
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

			graphics.DrawImage(texture->GetImage(), Gdiplus::Rect(INT(pos.x), INT(pos.y),
				INT(texture->GetWidth() * span.x * scale.x), INT(texture->GetHeight() * span.y * scale.y)),
				0, 0, texture->GetWidth(), texture->GetHeight(), Gdiplus::UnitPixel, &imgAttrib);
		}
	}
}
