#pragma once 
#include "Resource.h"
#include "Texture.h" 

namespace Bx
{
	class Animation : public Resource 
	{
	public:
		struct Sprite
		{
			Vector2 tLeftTop; 
			Vector2 tSize; 
			Vector2 tOffSet; 
			float	tTimeLag; 

			Sprite()
			: tLeftTop(Vector2::zero), tSize(Vector2::zero), tOffSet(Vector2::zero)
			{}
		};

		Animation();
		~Animation(); 

		HRESULT Load(const std::wstring& _path) override;

		void CreateAnimation(const std::wstring& _name, Texture* _spriteSheet,
			Vector2 _leftTop, Vector2 _size, Vector2 _offSet,
			UINT _spriteNum, float _timeLag); 

		void Reset(); 

		bool IsComplete() const { return isComplete; } 
		void SetAnimator(class Animator* _animator) { animator = _animator; } 

	private:
		//Animator�� Animation�� include�� ���¶� Animation���� 
		//Animator�� �ʿ��� ��� class ���� ���·� ����ϰ� �ִ�.
		class Animator* animator; 
		Texture* texture; 

		std::vector<Sprite> aniSheet; 
		int		index; 
		float	timeLag; 
		bool	isComplete; 
	};
}


