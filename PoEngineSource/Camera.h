#pragma once 
#include "GameObject.h" 

namespace Bx
{
	class Camera : public Component 
	{
	public: 
		Vector2 CalPos(Vector2& _pos)
		{
			Vector2 calPos = _pos - relativePos;
			return calPos; 
		}  

		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override; 

		void SetTarget(GameObject* _target) { target = _target; }

	private:		
		Vector2		relativePos; 
		Vector2		resolution; 
		Vector2		destPos;
		GameObject* target; 
	};
}

