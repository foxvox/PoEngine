#pragma once 
#include "GameObject.h" 
#include "GraphicDeviceDx11.h" 

using namespace std; 

namespace Bx
{
	class App
	{
	public:
		App(); 
		~App(); 
		void Initialize(HWND _hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
		void Release(); 
		void Destroy(); 

		UINT GetWidth() { return width; } 
		UINT GetHeight() { return height; } 
		HWND GetHWND() { return hwnd; }
		HDC  GetHDC() { return hdc; } 

		void ClearBackBuf(); 
		void SwapChain(HDC _disp, HDC _back); 
		void CreateBackBuf(UINT _width, UINT _height); 
		void GetWindow(HWND _hwnd, UINT _width, UINT _height); 

	private:
		std::unique_ptr<GraphicDeviceDx11> graphicDevice; 

		HWND		hwnd;
		HDC			hdc;
		HDC			backhdc; 
		HBITMAP		backBuf; 

		UINT		width; 
		UINT		height; 
	};
}





