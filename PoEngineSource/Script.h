#pragma once 
#include "Component.h" 
#include "Collider.h" 


namespace Bx
{
	class Script : public Component 
	{
	public:
		Script(); 
		~Script(); 

		virtual void OnCollisionEnter(Collider* rc);
		virtual void OnCollisionStay(Collider* rc);
		virtual void OnCollisionExit(Collider* rc);

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;		
	};
}


