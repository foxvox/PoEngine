#pragma once
#include "Component.h" 
#include "Animation.h" 
#include "Texture.h" 

namespace Bx
{
	class Animator : public Component 
	{
	public:
		Animator();
		~Animator(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override; 

		void CreateAnimation(const std::wstring& _name, Texture* _spriteSheet,
			Vector2 _leftTop, Vector2 _span, Vector2 _offSet, 
			UINT _spriteNum, float _timeLag); 

		Animation* FindAnimation(const std::wstring& _name); 
		void PlayAnimation(const std::wstring& _name, bool _isLoop = true); 

		bool IsCompleteAnimation() { return activeAnimation->IsComplete(); } 
		Animation* GetActiveAnimation() { return activeAnimation; } 

	private:
		std::map<std::wstring, Animation*> animations; 
		Animation* activeAnimation; 
		bool isLoop;  
	};
}

