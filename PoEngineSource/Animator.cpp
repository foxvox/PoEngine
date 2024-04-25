#include "Animator.h" 

namespace Bx
{
	Animator::Animator() 
		: Component(CompType::ANIMATOR), animations{}, activeAnimation(nullptr), isLoop(true) 
	{
	}

	Animator::~Animator()
	{
		for (auto& iter : animations)
		{
			if (iter.second == nullptr)
				continue; 

			delete iter.second; 
			iter.second = nullptr; 
		}

		for (auto& iter : eventPacks) 
		{
			if (iter.second == nullptr)
				continue;

			delete iter.second;
			iter.second = nullptr; 
		}
	}

	void Animator::Init()
	{}

	void Animator::Update()
	{
		if (activeAnimation)
		{
			activeAnimation->Update(); 

			EventPack* ep = FindEventPack(activeAnimation->GetName());

			if (activeAnimation->IsComplete() == true)
			{
				//애니가 다른 애니로의 전환 없이 완료된 경우 Complete 이벤트를 발생시킨다. 
				if (ep->Complete.event) 
					ep->Complete(); 

				if (isLoop == true) 
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
		ani->SetName(_name); 
		ani->CreateAnimation(_name, _spriteSheet, _leftTop, _span, _offSet, _frames, _timeLag); 		
		ani->SetAnimator(this); 
		
		EventPack* ep = new EventPack(); 
		eventPacks.insert(std::make_pair(_name, ep)); 

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

		//바로 아래쪽에서 새로 찾은 애니로 교체하고 있다. 교체하기 전에 이전 애니의 End 이벤트를 통해 
		//이전 애니를 마무리해 줄 수 있다.
		if (activeAnimation)
		{
			EventPack* curEp = FindEventPack(activeAnimation->GetName());
			if (curEp->End.event)
				curEp->End();
		} 

		//새로 찾은 애니의 Start 이벤트를 실행한다. 
		EventPack* nextEp = FindEventPack(ani->GetName());
		if (nextEp->Start.event)  
			nextEp->Start();

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
