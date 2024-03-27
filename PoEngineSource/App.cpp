#include "App.h" 

Po::App::App()
	: hWnd(nullptr), hDC(nullptr)
{
}

Po::App::~App()
{
}

void Po::App::Init(HWND _hWnd) 
{
	hWnd = _hWnd;
	hDC = GetDC(hWnd);
	player.SetPos(0.0f, 0.0f); 
}

void Po::App::Update()
{ 
	player.Update(); 
}

void Po::App::LateUpdate()
{
}

void Po::App::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Po::App::Render()
{
	player.Render(hDC); 
}


