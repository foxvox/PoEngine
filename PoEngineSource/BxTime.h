#pragma once 
#include "CommonInclude.h" 

namespace Bx
{
	class BxTime
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hDC);
		
		__forceinline static float DeltaTime() { return deltaTime; }

	private:
		static LARGE_INTEGER cpuFreq;
		static LARGE_INTEGER prevFreq;
		static LARGE_INTEGER curFreq;
		static float		 deltaTime;
	};
}


