#include "Animator.h" 

namespace Bx
{
	Animator::Animator() 
		: Component(CompType::ANI), animations{}, activeAnimaition(nullptr), isLoop(true) 
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Init()
	{
	}

	void Animator::Update()
	{
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC _hdc)
	{
	}
	void Animator::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _size, Vector2 _offSet, 
		UINT _spriteNum, float _timeLag)
	{

	}

	Animation* Animator::FindAnimation(const std::wstring& _name)
	{
		return nullptr;
	}

	void Animator::PlayAnimation(const std::wstring&, bool _isLoop)
	{
	}
}
