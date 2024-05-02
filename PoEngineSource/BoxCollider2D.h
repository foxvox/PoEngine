#pragma once
#include "Collider.h" 
#include "BxMath.h"

namespace Bx
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

	private:
		Vector2 size; 
	};
}


