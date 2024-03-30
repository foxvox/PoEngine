#include "Time.h" 

namespace Po
{
	LARGE_INTEGER Time::cpuFreq = {};
	LARGE_INTEGER Time::prevFreq = {};
	LARGE_INTEGER Time::curFreq = {};
	double		  Time::deltaTime = 0.0;

	void Time::Init()
	{
		//cpu ���������� 
		QueryPerformanceFrequency(&cpuFreq); 

		//���� ������ 
		QueryPerformanceCounter(&curFreq); 
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&curFreq);
		double diffOfFreq = static_cast<double>(curFreq.QuadPart - prevFreq.QuadPart); 

		deltaTime = diffOfFreq / static_cast<double>(cpuFreq.QuadPart);
		prevFreq.QuadPart = curFreq.QuadPart; 
	}

	void Time::Render(HDC hDC)
	{
		//static double time = 0.0f; 
		//time += deltaTime; 
		double fps = 1.0 / deltaTime;

		wchar_t str[50] = L""; 
		swprintf_s(str, 50, L"Time: %.2lf", fps); 
		int len = wcsnlen_s(str, 50); 
		TextOut(hDC, 0, 0, str, len);
	}
}


