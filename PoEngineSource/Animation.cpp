#include "Animation.h" 
#include "Time.h" 
#include "Transform.h"
#include "GameObject.h" 
#include "Animator.h" 
#include "Renderer.h" 
#include "Camera.h" 

namespace Bx
{
	Animation::Animation() 
		: Resource(ResrcType::ANI), 
		animator(nullptr), texture(nullptr), 
		aniSheet{}, index(-1), 
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

		timeLag += Time::GetDeltaTime();

		if (aniSheet[index].tTimeLag < timeLag)
		{
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
		Vector2 camPos{}; 

		if (camera)
		{
			camPos = camera->CalPos(pos); 
			pos = camPos; 
		}

		//알파블렌드를 쓰려면 해당 이미지에 알파채널이 있어야 한다. 
		BLENDFUNCTION func{}; 
		func.BlendOp = AC_SRC_OVER; 
		func.BlendFlags = 0; 
		func.AlphaFormat = AC_SRC_ALPHA; 
		func.SourceConstantAlpha = 255;  //0=>transparent, 255=>Opaque 

		Sprite sprite = aniSheet[index]; 
		HDC imghdc = texture->GetHDC(); 

		AlphaBlend(_hdc, pos.x, pos.y, sprite.tSpan.x, sprite.tSpan.y, imghdc, 
			sprite.tLeftTop.x, sprite.tLeftTop.y, sprite.tSpan.x, sprite.tSpan.y, func);
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
