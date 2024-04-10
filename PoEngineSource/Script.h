#pragma once 
#include "Component.h" 


namespace Bx
{
	class Script : public Component 
	{
	public:
		Script(); 
		~Script(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;		
	};
}


