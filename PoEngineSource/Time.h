#pragma once 
#include "CommonInclude.h" 
namespace Bx
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hDC);
		static double GetDeltaTime()
		{
			return deltaTime; 
		}

	private:
		static LARGE_INTEGER cpuFreq;
		static LARGE_INTEGER prevFreq;
		static LARGE_INTEGER curFreq;
		static double		 deltaTime;
	};
}


