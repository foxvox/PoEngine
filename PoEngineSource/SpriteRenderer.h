#pragma once
#include "Component.h" 

namespace Bx
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
		
		void ImageLoad(const std::wstring& path); 

	private:
		Gdiplus::Image* image; 
		UINT			width;
		UINT			height; 
	};
}



