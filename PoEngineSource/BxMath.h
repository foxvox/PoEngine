#pragma once 
#include <cmath>

static constexpr auto PI = 3.141592;

namespace Bx 
{
	static float DegToRad(float _deg) { return _deg * (PI / 180.f); } 
	static float RadToDeg(float _rad) { return _rad * (180.f / PI); } 

	struct Vector2
	{
	public: 
		float x;
		float y;

		static Vector2 one;
		static Vector2 zero;
		static Vector2 right; 
		static Vector2 left; 
		static Vector2 up; 
		static Vector2 down; 

		Vector2()
			: x(0.f), y(0.f) 
		{} 

		Vector2(const Vector2& _v)
			: x(_v.x), y(_v.y) 
		{}

		Vector2(float _x, float _y) 
			: x(_x), y(_y)
		{} 

		void operator+= (Vector2 _rv)
		{
			x += _rv.x; 
			y += _rv.y;
		}

		void operator-= (Vector2 _rv)
		{
			x -= _rv.x;
			y -= _rv.y;
		}

		void operator*=(Vector2 _rv)
		{
			x *= _rv.x;
			y *= _rv.y;
		}

		void operator*=(float _value)
		{
			x *= _value;
			y *= _value;
		}

		Vector2 operator- ()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator+ (Vector2 _rv)
		{
			return Vector2(x + _rv.x, y + _rv.y);
		}

		Vector2 operator- (Vector2 _rv)
		{
			return Vector2(x - _rv.x, y - _rv.y);
		}

		Vector2 operator* (Vector2 _rv)
		{
			return Vector2(x * _rv.x, y * _rv.y); 
		}

		Vector2 operator* (float _value)
		{
			return Vector2(x * _value, y * _value);
		}

		Vector2 operator/ (float _value)
		{
			return Vector2(x / _value, y / _value);
		}

		bool operator==(Vector2 _rv)
		{
			return (x == _rv.x) && (y == _rv.y);
		}

		void Clear() { x = 0.f; y = 0.f; } 

		float Length() { return sqrtf(x * x + y * y); } 

		Vector2 Normalize()
		{
			float len = Length();
			x /= len; 
			y /= len; 

			return *this;
		}

		Vector2 Rotate(float _deg)
		{
			float rad = (_deg / 180.f) * PI;
			this->Normalize(); 
			float px = cosf(rad) * x - sinf(rad) * y;
			float py = sinf(rad) * x + cosf(rad) * y;

			return Vector2(px, py);
		}

		float Dot(Vector2& _rv) const 
		{
			return x * _rv.x + y * _rv.y;
		}

		float Cross(Vector2& _rv) const 
		{
			return x * _rv.y - y * _rv.x;
		}
	};
}

