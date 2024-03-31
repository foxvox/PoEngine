#pragma once 
#include "Component.h" 

namespace Po
{
	class Transform :public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void SetPos(float _x, float _y) { x = _x; y = _y; } 
		float GetX() { return x; } 
		float GetY() { return y; } 

	private:
		float x; 
		float y; 
	};
}


