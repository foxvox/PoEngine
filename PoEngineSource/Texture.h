#pragma once 
#include "Resource.h" 

namespace Bx
{ 
	class Texture : public Resource 
	{
	public: 
		enum class TextureType
		{
			BMP, PNG, NONE,
		}; 

		static Texture* Create(const std::wstring& _name, UINT _width, UINT _height); 

		Texture(); 
		~Texture(); 

		virtual HRESULT Load(const std::wstring& _path); 

		UINT GetWidth() { return width; }
		void SetWidth(UINT _width) { width = _width; } 
		UINT GetHeight() { return height; } 
		void SetHeight(UINT _height) { height = _height; }
		HDC GetHDC() { return hdc; } 
		TextureType GetTextureType() { return txType; } 
		Gdiplus::Image* GetImage() { return image; }
		bool IsAlpha() { return isAlpha; } 

	private:
		bool			 isAlpha; 
		TextureType		 txType; 
		Gdiplus::Image*	 image;
		HBITMAP			 bitmap; 
		HDC				 hdc; 
		UINT			 width;
		UINT			 height;
	};
}



