#pragma once 
#include "Entity.h" 
#include "Component.h" 
#include "PoMath.h" 

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

		void SetPos(Vector2 _pos) { position.x = _pos.x; position.y = _pos.y; } 
		Vector2 GetPos() const { return position; } 

	private: 
		Vector2 position; 
	};
}


