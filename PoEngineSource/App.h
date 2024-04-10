#pragma once 
#include "GameObject.h" 

using namespace std; 

namespace Bx
{
	class App
	{
	public:
		App(); 
		~App(); 
		void Init(HWND _hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HDC  GetHDC() const { return hdc; } 
		void ClearBackBuf(); 
		void SwapChain(HDC disp, HDC back); 
		void CreateBackBuf(UINT _width, UINT _height); 
		void GetWindow(HWND _hwnd, UINT _width, UINT _height); 

	private:
		HWND		hwnd;
		HDC			hdc;
		HDC			backhdc; 
		HBITMAP		backBuf; 

		UINT		width; 
		UINT		height; 
	};
}





