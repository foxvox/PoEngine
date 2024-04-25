#include "Animator.h" 

namespace Bx
{
	Animator::Animator() 
		: Component(CompType::ANI), animations{}, activeAnimation(nullptr), isLoop(true) 
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
		if (activeAnimation)
		{
			activeAnimation->Update(); 
			if (activeAnimation->IsComplete() == true && isLoop == true)
			{
				activeAnimation->Reset(); 
			}
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC _hdc)
	{
		if (activeAnimation)
			activeAnimation->Render(_hdc); 
	}

	void Animator::CreateAnimation(const std::wstring& _name, Texture* _spriteSheet, 
		Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
		UINT _frames, float _timeLag)
	{
		Animation* ani = nullptr; 
		
		ani = FindAnimation(_name);
		if (ani != nullptr)
			return; 

		ani = new Animation(); 
		ani->CreateAnimation(_name, _spriteSheet, _leftTop, _span, _offSet, _frames, _timeLag); 		
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

		activeAnimation = ani; 
		activeAnimation->Reset(); 
		isLoop = _isLoop; 
	}

	Animator::EventPack* Animator::FindEventPack(const std::wstring& _name)
	{
		auto iter = eventPacks.find(_name);
		if (iter == eventPacks.end())
			return nullptr;

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& _name)
	{
		EventPack* ep = FindEventPack(_name); 
		return ep->Start.event;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& _name)
	{
		EventPack* ep = FindEventPack(_name);
		return ep->Complete.event; 
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& _name)
	{
		EventPack* ep = FindEventPack(_name);
		return ep->End.event;
	}
}
