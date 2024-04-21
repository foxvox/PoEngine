#pragma once 
#include "Script.h" 
#include "Transform.h"

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

		enum class Dir
		{
			LEFT, 
			RIGHT, 
			UP, 
			DOWN, 
			END, 
		};

		CatScript();
		~CatScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void Sit();
		void Move();
		void AniByMovingDir(Dir _dir); 
		void CatMoving(Transform* _tr); 

	private:
		State state;
		class Animator* animator;
		float catTime; 
		Dir   direction; 
	};
}


