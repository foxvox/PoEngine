#include "Animation.h" 
#include "BxTime.h" 
#include "Transform.h"
#include "GameObject.h" 
#include "Animator.h" 
#include "Renderer.h" 
#include "Camera.h" 
#include "Texture.h" 

namespace Bx
{
	Animation::Animation() 
		: Resource(ResrcType::ANI), 
		animator(nullptr), texture(nullptr), 
		aniSheet{}, index(0), 
		timeLag(0.f), isComplete(false) 
	{}

	Animation::~Animation()
	{}

	HRESULT Animation::Load(const std::wstring& _path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (isComplete)
			return; 

		timeLag += BxTime::DeltaTime();

		if (aniSheet[index].tTimeLag < timeLag)
		{
			timeLag = 0.f; 

			if (index < aniSheet.size() - 1)
				index++; 			
			else 
				isComplete = true; 			
		} 
	}

	void Animation::Render(HDC _hdc)
	{
		if (texture == nullptr)
			return; 

		GameObject* gameObj = animator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>(); 
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRot();
		Vector2 pos = tr->GetPos(); 		
		
		Vector2 camPos{}; 		
		//Renderer.h 안에 선언되어 있음.
		if (mainCam)
		{
			camPos = mainCam->CalPos(pos); 
			pos = camPos; 
		}		 

		Sprite sprite = aniSheet[index];
		Texture::TextureType tt = texture->GetTextureType(); 
		if (tt == Texture::TextureType::PNG)
		{
			//내가 원하는 픽셀을 투명화 시킬 때 
			Gdiplus::ImageAttributes imgAttrib{}; 
			//투명화 시킬 픽셀의 색 범위
			imgAttrib.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255)); 

			Gdiplus::Graphics graphics(_hdc);

			//회전 
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot); 
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(texture->GetImage(), 
				Gdiplus::Rect(int(pos.x - (sprite.tSpan.x / 2.f)), int(pos.y - (sprite.tSpan.y / 2.f)), 
					int(sprite.tSpan.x * scale.x), int(sprite.tSpan.y * scale.y)),
				int(sprite.tLeftTop.x), int(sprite.tLeftTop.y),
				int(sprite.tSpan.x), int(sprite.tSpan.y), 
				Gdiplus::UnitPixel, /*&imgAttrib*/nullptr);
		}
		else if (tt == Texture::TextureType::BMP) 
		{
			HDC imghdc = texture->GetHDC();

			if (texture->IsAlpha())
			{
				//알파블렌드를 쓰려면 해당 이미지에 알파채널이 있어야 한다. 
				BLENDFUNCTION func{};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;  //0=>transparent, 255=>Opaque 				

				AlphaBlend(_hdc,
					int(pos.x - (sprite.tSpan.x / 2.f) + sprite.tOffSet.x), int(pos.y - (sprite.tSpan.y / 2.f) + sprite.tOffSet.y), 
					int(sprite.tSpan.x * scale.x), int(sprite.tSpan.y * scale.y), imghdc,
					int(sprite.tLeftTop.x), int(sprite.tLeftTop.y), int(sprite.tSpan.x), int(sprite.tSpan.y), func);
			}
			else
			{
				TransparentBlt(_hdc, 
					int(pos.x - (sprite.tSpan.x / 2.f) + sprite.tOffSet.x), int(pos.y - (sprite.tSpan.y / 2.f) + sprite.tOffSet.y),
					int(sprite.tSpan.x * scale.x), int(sprite.tSpan.y * scale.y), imghdc,
					int(sprite.tLeftTop.x), int(sprite.tLeftTop.y), int(sprite.tSpan.x), int(sprite.tSpan.y), RGB(255, 0, 255));
			}

			Rectangle(_hdc, pos.x, pos.y, pos.x + 20, pos.y + 20); 
		}
	}

	void Animation::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
		UINT _frames, float _timeLag)
	{
		texture = _spriteSheet; 
		for (size_t i = 0; i < _frames; i++)
		{
			Sprite sprite{}; 
			sprite.tLeftTop.x = _leftTop.x + _span.x * i; 
			sprite.tLeftTop.y = _leftTop.y; 
			sprite.tSpan = _span; 
			sprite.tOffSet = _offSet; 
			sprite.tTimeLag = _timeLag; 

			aniSheet.push_back(sprite); 
		}
	}

	void Animation::Reset()
	{
		timeLag = 0.f; 
		index = 0; 
		isComplete = false; 
	}
}
