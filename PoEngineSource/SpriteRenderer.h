#pragma once
#include "Component.h" 
#include "Texture.h" 

namespace Bx
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
		
		//void ImageLoad(const std::wstring& _path); 
		void SetTexture(Texture* _texture) { texture = _texture; } 
		void SetSize(Vector2 _size) { size = _size; } 

	private:
		Texture*	texture; 
		Vector2		size;
	};
}



