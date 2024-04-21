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
	{
	}

	Animation::~Animation()
	{
	}

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
		Vector2 pos = tr->GetPos(); 
		float rot = tr->GetRot();
		Vector2 scale = tr->GetScale();
		
		//Vector2 camPos{}; 
		/*
		if (camera)
		{
			camPos = camera->CalPos(pos); 
			pos = camPos; 
		}
		*/ 

		Sprite sprite = aniSheet[index];

		Texture::TextureType tt = texture->GetTextureType(); 
		if (tt == Texture::TextureType::PNG)
		{
			//내가 원하는 픽셀을 투명화 시킬 때 
			Gdiplus::ImageAttributes imgAttrib{}; 
			//투명화 시킬 픽셀의 색 범위
			imgAttrib.SetColorKey(Gdiplus::Color(240, 240, 240), Gdiplus::Color(255, 255, 255)); 

			Gdiplus::Graphics graphics(_hdc);

			//회전 
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot); 
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(texture->GetImage(), 
				Gdiplus::Rect(pos.x - (sprite.tSpan.x / 2.f), pos.y - (sprite.tSpan.y / 2.f), 
					sprite.tSpan.x * scale.x, sprite.tSpan.y * scale.y),
				sprite.tLeftTop.x, sprite.tLeftTop.y,
				sprite.tSpan.x, sprite.tSpan.y, 
				Gdiplus::UnitPixel, &imgAttrib);
		}
		else if (tt == Texture::TextureType::BMP) 
		{
			//알파블렌드를 쓰려면 해당 이미지에 알파채널이 있어야 한다. 
			BLENDFUNCTION func{};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 100;  //0=>transparent, 255=>Opaque 
			
			HDC imghdc = texture->GetHDC();

			AlphaBlend(_hdc, 
				pos.x - (sprite.tSpan.x / 2.f), pos.y - (sprite.tSpan.y / 2.f), 
				sprite.tSpan.x * scale.x, sprite.tSpan.y * scale.y, imghdc,
				sprite.tLeftTop.x, sprite.tLeftTop.y,
				sprite.tSpan.x, sprite.tSpan.y, func);
		}
	}

	void Animation::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
		UINT _spriteNum, float _timeLag)
	{
		texture = _spriteSheet; 
		for (size_t i = 0; i < _spriteNum; i++)
		{
			Sprite sprite = {}; 
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
