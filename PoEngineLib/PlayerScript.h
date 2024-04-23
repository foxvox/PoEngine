#pragma once 
#include "Script.h" 

namespace Bx
{
	class PlayerScript : public Script 
	{
	public:
		enum class State
		{
			IDLE,
			MOVE,
			SLEEP,
			GIVEWATER, 
			ATTACK,
		};

		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void Idle(); 
		void Move(); 
		void GiveWater(); 

	private:
		State state; 
		class Animator* animator; 
	};
}


