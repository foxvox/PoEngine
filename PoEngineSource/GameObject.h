#pragma once 
#include "Input.h" 

namespace Po
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate(); 
		void Render(HDC _hDC); 

		void SetPos(float _x, float _y)
		{
			x = _x; 
			y = _y; 
		}

		float GetPosX() const { return x; } 
		float GetPosY() const { return y; }

	private:
		float x; 
		float y; 
	};
}


