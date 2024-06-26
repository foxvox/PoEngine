#pragma once
#include "Component.h" 
#include "Texture.h" 
#include "BxMath.h"

namespace Bx
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer(); 

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
		
		void SetTexture(Texture* _texture) { texture = _texture; } 
		void SetSpan(Vector2 _span) { span = _span; } 

	private:
		Texture*	texture; 
		Vector2		span;
	};
}



