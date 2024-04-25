#pragma once 
#include "CommonInclude.h" 
namespace Bx
{
	class BxTime
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hDC);
		static float DeltaTime() {	return deltaTime; }

	private:
		static LARGE_INTEGER cpuFreq;
		static LARGE_INTEGER prevFreq;
		static LARGE_INTEGER curFreq;
		static float		 deltaTime;
	};
}


