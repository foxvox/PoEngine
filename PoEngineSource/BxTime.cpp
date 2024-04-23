#include "BxTime.h" 

namespace Bx
{
	LARGE_INTEGER BxTime::cpuFreq{};
	LARGE_INTEGER BxTime::prevFreq{};
	LARGE_INTEGER BxTime::curFreq{};
	float		  BxTime::deltaTime = 0.f; 

	void BxTime::Init()
	{
		//cpu 고유진동수 
		QueryPerformanceFrequency(&cpuFreq); 

		//현재 진동수 
		QueryPerformanceCounter(&curFreq); 
	}

	void BxTime::Update()
	{
		QueryPerformanceCounter(&curFreq);
		double diffOfFreq = static_cast<double>(curFreq.QuadPart - prevFreq.QuadPart); 

		deltaTime = float(diffOfFreq / static_cast<double>(cpuFreq.QuadPart)); 

		//첫번째 시도는 pass하고 두번째 시도부터 deltaTime 사용
		if (deltaTime > 1.f)
			deltaTime = 0.f; 					
		
		prevFreq.QuadPart = curFreq.QuadPart; 
	}

	void BxTime::Render(HDC _hdc)
	{		
		double fps = 1.0 / deltaTime;

		wchar_t str[50] = L""; 
		swprintf_s(str, 50, L"fps: %.2lf", fps); 
		int len = int(wcsnlen_s(str, 50)); 
		TextOutW(_hdc, 0, 0, str, len);
	}
}


