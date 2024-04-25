#pragma once 
#include "Resource.h"
#include "Texture.h" 

namespace Bx
{
	//Animation < Resource < Entity : Entity SetName, GetName  
	class Animation : public Resource 
	{
	public:
		struct Sprite
		{
			Vector2 tLeftTop; 
			Vector2 tSpan; 
			Vector2 tOffSet; 
			float	tTimeLag; 

			Sprite()
			: tLeftTop(Vector2::zero), tSpan(Vector2::zero), 
				tOffSet(Vector2::zero), tTimeLag(0.f) 
			{}
		};

		Animation();
		~Animation(); 

		HRESULT Load(const std::wstring& _path) override;

		void Update();
		void Render(HDC _hdc); 

		void CreateAnimation(const std::wstring& _name, Texture* _spriteSheet,
			Vector2 _leftTop, Vector2 _span, Vector2 _offSet,
			UINT _frames, float _timeLag); 

		void Reset(); 

		bool IsComplete() const { return isComplete; } 
		void SetAnimator(class Animator* _animator) { animator = _animator; } 

	private:
		//Animator가 Animation을 include한 상태라서 Animation에서 
		//Animator가 필요한 경우 class 선언 형태로 사용하고 있다.
		class Animator* animator; 
		Texture*		texture; 

		std::vector<Sprite> aniSheet; 
		int		index; 
		float	timeLag; 
		bool	isComplete; 
	};
}


