#pragma once 
#include <Windows.h> 

namespace Po
{
	class App
	{
		App(); 
		~App(); 
		void Init(HWND _hWnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND	hWnd;
		HDC		hDC;
		float	speed;
		float	x, y;
	};
}





