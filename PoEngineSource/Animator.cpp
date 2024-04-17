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
		if (activeAnimaition)
		{
			activeAnimaition->Update(); 
			if (activeAnimaition->IsComplete() == true && isLoop == true)
			{
				activeAnimaition->Reset(); 
			}
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC _hdc)
	{
		if (activeAnimaition)
			activeAnimaition->Render(_hdc); 
	}

	void Animator::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
		UINT _spriteNum, float _timeLag)
	{
		Animation* ani = nullptr; 
		
		ani = FindAnimation(_name);
		if (ani != nullptr)
			return; 

		ani = new Animation(); 
		ani->CreateAnimation(_name, _spriteSheet, _leftTop, _span, _offSet, _spriteNum, _timeLag); 		
		ani->SetAnimator(this); 
		animations.insert(std::make_pair(_name, ani)); 
	}

	Animation* Animator::FindAnimation(const std::wstring& _name)
	{
		auto iter = animations.find(_name); 
		if (iter == animations.end())
			return nullptr; 

		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& _name, bool _isLoop)
	{
		Animation* ani = FindAnimation(_name); 
		if (ani == nullptr)
			return; 

		activeAnimaition = ani; 
		activeAnimaition->Reset(); 
		isLoop = _isLoop; 
	}
}
