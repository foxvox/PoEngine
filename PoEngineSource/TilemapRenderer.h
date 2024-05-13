#pragma once
#include "Component.h" 
#include "Texture.h" 
#include "BxMath.h"

namespace Bx
{
	class TilemapRenderer : public Component
	{
	public:
		static Vector2 tileSpanV;
		static Vector2 originTileSpan;
		static Vector2 selectedIndex;

		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void SetTexture(Texture* _texture) { texture = _texture; }
		void SetMultiple(Vector2 _multiple) { multiple = _multiple; }
		Vector2 GetIndex() { return index; }
		void SetIndex(Vector2 _index) { index = _index; }

	private:
		Texture*	texture;
		Vector2		multiple;
		Vector2		index; 
		Vector2		tileSpan; 
	};
}


