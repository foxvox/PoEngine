#pragma once 
#include "GameObject.h" 

namespace Po
{
	class App
	{
	public:
		App(); 
		~App(); 
		void Init(HWND _hWnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND		hWnd;
		HDC			hDC;
		HDC			backHDC; 
		HBITMAP		backBuf; 

		UINT		width; 
		UINT		height; 

		GameObject	player;
	};
}





