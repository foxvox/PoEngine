#include "Texture.h" 
#include "App.h" 
#include "Resources.h" 

extern Bx::App app;  // 외부 파일에 있는 전역변수를 사용하겠다고 전방선언 

namespace Bx
{
	Texture* Texture::Create(const std::wstring& _name, UINT _width, UINT _height)
	{
		Texture* img = Resources::Find<Texture>(_name);
		if (img)
			return img; 

		img = new Texture(); 
		img->SetName(_name); 
		img->SetWidth(_width); 
		img->SetHeight(_height); 

		HDC hdc = app.GetHDC(); 
		HWND hwnd = app.GetHWND();
		
		img->bitmap = CreateCompatibleBitmap(hdc, _width, _height);		
		img->hdc = CreateCompatibleDC(hdc); 

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		::Rectangle(img->hdc, -1, -1, img->GetWidth() + 1, img->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(img->hdc, img->bitmap);
		DeleteObject(oldBitmap); 

		Resources::Insert(_name + L"Image", img);

		return img;
	}

	Texture::Texture()
		: Resource(ResrcType::TEXTURE), txType(TextureType::NONE), width(0), height(0), 
		hdc(nullptr), bitmap(nullptr), image(nullptr), isAlpha(false) 
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
				return S_FALSE;		// S_FALSE <== ((HRESULT)1L)로 정의되어 있음, S_OK <== ((HRESULT)0L)로 정의되어 있음 

			BITMAP info{}; 
			GetObject(bitmap, sizeof(BITMAP), &info); 

			width = info.bmWidth; 
			height = info.bmHeight; 
			txType = TextureType::BMP; 

			if (info.bmBitsPixel == 32)
				isAlpha = true;
			else if (info.bmBitsPixel == 24)
				isAlpha = false; 

			HDC mainDC = app.GetHDC(); 
			hdc = CreateCompatibleDC(mainDC); 
			HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap); 
			DeleteObject(oldBitmap); 
		}

		return S_OK;
	}
}
