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
		/* PlayerScript���� ó���ϱ�� �� deprecated 
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
		Vector2 camPos = camera->CalPos(pos); 

		//ķ��ġ�� ���ӿ�����Ʈ ��ġ�� �Ҵ�, ī�޶� ���۵��� �Ҵ� ���
		//pos = camPos; 

		if (texture->GetTextureType() == Texture::TextureType::PNG) 
		{
			Gdiplus::Graphics graphics(_hdc);
			graphics.DrawImage(texture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y));
		}
		else if (texture->GetTextureType() == Texture::TextureType::BMP) 
		{
			//dest���� src���߿� 
			TransparentBlt(_hdc, pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y,
				texture->GetHDC(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255)); 
		}

		
	}

}
