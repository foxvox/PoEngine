#include "Texture.h" 
#include "App.h"  

extern Bx::App app;  // �ܺ� ���Ͽ� �ִ� ���������� ����ϰڴٰ� ���漱�� 

namespace Bx
{
	Texture::Texture() 
		: Resource(ResrcType::TEXTURE), txType(TextureType::NONE), width(0), height(0), 
		hdc(nullptr), bitmap(nullptr), image(nullptr) 
	{}								

	Texture::~Texture()			
	{}

	HRESULT Texture::Load(const std::wstring& _path)
	{
		std::wstring ext = _path.substr(_path.find_last_of(L".") + 1); 

		if (ext == L"png")
		{
			image = Gdiplus::Image::FromFile(_path.c_str());

			if (image == nullptr)
				return S_FALSE; 

			width = image->GetWidth();
			height = image->GetHeight();
			txType = TextureType::PNG; 
		}
		else if (ext == L"bmp") 
		{
			bitmap = (HBITMAP)LoadImageW(nullptr, _path.c_str(), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); 
			
			if (bitmap == nullptr)
				return S_FALSE;		// S_FALSE <== ((HRESULT)1L)�� ���ǵǾ� ����, S_OK <== ((HRESULT)0L)�� ���ǵǾ� ���� 

			BITMAP info{}; 
			GetObject(bitmap, sizeof(BITMAP), &info); 

			width = info.bmWidth; 
			height = info.bmHeight; 
			txType = TextureType::BMP; 

			HDC mainDC = app.GetHDC(); 
			hdc = CreateCompatibleDC(mainDC); 
			HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap); 
			DeleteObject(oldBitmap); 
		}

		return S_OK;
	}
}
