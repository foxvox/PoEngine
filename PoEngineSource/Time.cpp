#include "Time.h" 

namespace Bx
{
	LARGE_INTEGER Time::cpuFreq{};
	LARGE_INTEGER Time::prevFreq{};
	LARGE_INTEGER Time::curFreq{};
	double		  Time::deltaTime = 0; 

	void Time::Init()
	{
		//cpu 고유진동수 
		QueryPerformanceFrequency(&cpuFreq); 

		//현재 진동수 
		QueryPerformanceCounter(&curFreq); 
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&curFreq);
		double diffOfFreq = static_cast<double>(curFreq.QuadPart - prevFreq.QuadPart); 

		deltaTime = diffOfFreq / static_cast<double>(cpuFreq.QuadPart);
		prevFreq.QuadPart = curFreq.QuadPart; 
	}

	void Time::Render(HDC _hdc)
	{
		/*
		double fps = 1.0 / deltaTime;

		wchar_t str[50] = L""; 
		swprintf_s(str, 50, L"fps: %.2lf", fps); 
		int len = wcsnlen_s(str, 50); 
		TextOutW(_hdc, 0, 0, str, len);
		*/
	}
}


