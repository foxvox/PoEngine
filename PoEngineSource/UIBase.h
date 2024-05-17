#pragma once
#include "Entity.h"

namespace Bx
{
	class UIBase : public Entity 
	{ 
	public:
		UIBase(); 
		~UIBase(); 

		/// <summary>
		/// ui가 로드 되었을 때 초기화 해주는 함수 
		/// </summary>
		void Initialize();
		/// <summary>
		/// ui가 활성화 되었을 때 호출되는 함수 
		/// </summary>
		void Active(); 
		void Inactive(); 
		void Update();
		void LateUpdate();
		void Render(HDC _hdc);

		void UIClear(); 

		virtual void OnInit(); 
		virtual void OnActive(); 
		virtual void OnInactive(); 
		virtual void OnUpdate(); 
		virtual void OnClear(); 

		UIType GetType() { return type; } 
		void   SetFullScreen(bool _on) { isActive = _on; }
		bool   IsFullScreen() { return isFullScreen; }

	private:
		UIType type; 
		bool   isFullScreen; 
		bool   isActive; 
	};
}
