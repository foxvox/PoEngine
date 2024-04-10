#pragma once 

namespace Bx
{
	struct Vector2
	{
		float x;
		float y;

		static Vector2 one; 
		static Vector2 zero; 

		Vector2()
			: x(0.f), y(0.f)
		{}

		Vector2(float _x, float _y)
			: x(_x), y(_y)
		{}
	};
}

