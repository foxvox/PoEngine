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

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void Idle(); 
		void Move(); 
		void GiveWater(); 

		void AttackEffect();

		void OnCollisionEnter(Collider* rc) override;
		void OnCollisionStay(Collider* rc) override;
		void OnCollisionExit(Collider* rc) override;

	private:
		State state; 
		class Animator* animator; 
	};
}


