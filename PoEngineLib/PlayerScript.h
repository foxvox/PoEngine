#pragma once 
#include "Script.h" 

namespace Bx
{
	class PlayerScript : public Script 
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
	};
}


