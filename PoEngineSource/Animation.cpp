#include "Animation.h" 

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
	void Animation::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _size, Vector2 _offSet, 
		UINT _spriteNum, float _timeLag)
	{
	}
	void Animation::Reset()
	{
	}
}
