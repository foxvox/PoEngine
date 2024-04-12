#pragma once 

namespace Bx
{
	struct Vector2
	{
	public: 
		float x;
		float y;

		static Vector2 one; 
		static Vector2 zero; 

		Vector2()
			: x(0.f), y(0.f)
		{} 

		Vector2(const Vector2& _vec) 
			: x(_vec.x), y(_vec.y) 
		{}

		Vector2(float _x, float _y)
			: x(_x), y(_y)
		{}

		Vector2 operator-(Vector2& _right) 
		{
			return Vector2(x - _right.x, y - _right.y); 
		} 

		Vector2 operator+(Vector2& _right) 
		{
			return Vector2(x + _right.x, y + _right.y);
		}

		Vector2 operator/(float _right)
		{
			return Vector2(x / _right, y / _right); 
		}
	};
}

