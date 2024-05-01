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
			LAYDOWN, 
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

		Vector2 dest;

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void Sit();
		void Move();
		void AniByMovingDir(Dir _dir); 
		void CatMoving(Transform* _tr); 
		void LayDown(); 
		void SetPlayer(GameObject* _player) { player = _player; } 		

	private:
		State state;
		class Animator* animator;
		float catTime; 
		Dir   direction; 
		float activeTime;

		GameObject* player;	
		float radian; 
	};
}


