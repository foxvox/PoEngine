#pragma once 
#include "GameObject.h" 
#include "Input.h" 

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
		HWND	hWnd;
		HDC		hDC;

		GameObject player;
	};
}





