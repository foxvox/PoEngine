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
		/// ui�� �ε� �Ǿ��� �� �ʱ�ȭ ���ִ� �Լ� 
		/// </summary>
		void Initialize();
		/// <summary>
		/// ui�� Ȱ��ȭ �Ǿ��� �� ȣ��Ǵ� �Լ� 
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
