#pragma once
#include "Component.h" 
#include "Animation.h" 
#include "Texture.h" 

namespace Bx
{
	class Animator : public Component 
	{
	public:
		struct Event
		{
			// 대입연산자 재정의
			void operator=(std::function<void()> func)
			{
				event = std::move(func); 
			}

			void operator()()
			{
				if (event)
					event;  // event == event() 
			}

			//void (*evnet)(); <= 함수포인터 표현법 void: return, (): param
			std::function<void()> event;  //functor(함수객체)표현법 
		};

		struct EventPack
		{
			Event Start;
			Event Complete;
			Event End;
		};

		Animator();
		~Animator(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override; 

		void CreateAnimation(const std::wstring& _name, Texture* _spriteSheet,
			Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
			UINT _frames, float _timeLag); 

		Animation* FindAnimation(const std::wstring& _name); 
		void PlayAnimation(const std::wstring& _name, bool _isLoop = true); 
		bool IsAnimationComplete() { return activeAnimation->IsComplete(); } 
		Animation* GetActiveAnimation() { return activeAnimation; } 

		EventPack* FindEventPack(const std::wstring& _name);
		std::function<void()>& GetStartEvent(const std::wstring& _name);
		std::function<void()>& GetCompleteEvent(const std::wstring& _name);
		std::function<void()>& GetEndEvent(const std::wstring& _name);

	private:
		std::map<std::wstring, Animation*> animations; 
		Animation* activeAnimation; 
		bool isLoop; 

		std::map<std::wstring, EventPack*> eventPacks; 
	};
}

