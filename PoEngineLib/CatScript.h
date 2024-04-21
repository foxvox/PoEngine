#pragma once 
#include "Script.h" 

namespace Bx
{
	class CatScript : public Script
	{
	public:
		enum class State
		{
			SIT,
			MOVE,
			SLEEP,
			ATTACK,
		};

		CatScript();
		~CatScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void Sit();
		void Move();

	private:
		State state;
		class Animator* animator;
	};
}


