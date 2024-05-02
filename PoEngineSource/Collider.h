#pragma once
#include "Component.h" 
#include "BxMath.h"

namespace Bx
{
	class Collider : public Component 
	{
	public:
		Collider();
		~Collider();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc); 

		Vector2 GetOffset() { return offset; } 
		void	SetOffset(Vector2 _offset) { offset = _offset; } 
	private:
		Vector2 offset; 
	};
}



