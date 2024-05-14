#pragma once
#include "Component.h"
#include "BxMath.h"

namespace Bx
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void	SetMass(float _mass) { mass = _mass; }
		void	AddForce(Vector2 _force) { force = _force; }
		void	SetGround(bool _ground) { ground = _ground; }
		void	SetVelocity(Vector2 _velocity) { velocity = _velocity; }
		Vector2 GetVelocity() { return velocity; }


	private:
		bool	ground;
		float	mass;
		float	friction;

		Vector2 force;
		Vector2 accel;
		Vector2 velocity;
		Vector2 limVelocity;
		Vector2 gravity;
	};
}


