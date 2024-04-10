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

		UINT GetWidth() const { return width; }
		UINT GetHeight() const { return height; } 
		HDC GetHDC() const { return hdc; } 
		TextureType GetTextureType() const { return txType; } 
		Gdiplus::Image* GetImage() const { return image; }

	private:
		TextureType		 txType; 
		Gdiplus::Image*	 image;
		HBITMAP			 bitmap; 
		HDC				 hdc; 
		UINT			 width;
		UINT			 height;
	};
}



