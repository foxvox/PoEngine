#pragma once 
#include "Resource.h" 

namespace Bx
{ 
	class Texture : public Resource 
	{
	public: 
		enum class TextureType
		{
			Bmp, Png, None,
		};

		Texture(); 
		~Texture(); 

		virtual HRESULT Load(const std::wstring& _path); 

		UINT GetWidth() { return width; }
		UINT GetHeight() { return height; } 
		HDC GetHDC() { return hdc; } 
		TextureType GetTextureType() { return txType; } 
		Gdiplus::Image* GetImage() { return image; }

	private:
		TextureType		 txType; 
		Gdiplus::Image*	 image;
		HBITMAP			 bitmap; 
		HDC				 hdc; 
		UINT			 width;
		UINT			 height;
	};
}



