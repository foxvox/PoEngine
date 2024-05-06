#pragma once 
#include "Collider.h" 

namespace Bx
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);
	private:
		float radius; 
	};
}


