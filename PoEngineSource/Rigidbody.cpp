#include "Rigidbody.h"
#include "BxTime.h"
#include "Transform.h"
#include "GameObject.h"

namespace Bx
{
	Rigidbody::Rigidbody()
		: Component(CompType::RIGIDBODY), ground(false), mass(1.f), friction(100.f), 
		force(Vector2::Zero), velocity(Vector2::Zero), limVelocity(Vector2(200.f, 1000.f)), 
		gravity(Vector2(0.f, 800.f)), accel(Vector2::Zero) 
	{}

	Rigidbody::~Rigidbody()
	{}

	void Rigidbody::Initialize()
	{}

	void Rigidbody::Update()
	{		
		// f(힘) = m(질량) x a(가속도)
		// a = f / m;
		accel = force / mass;

		// 속도에 가속도를 더한다.
		velocity += accel * BxTime::DeltaTime();

		if (ground)
		{
			// 땅위에 있을때
			Vector2 tmpGravity = gravity;
			tmpGravity.Normalize();

			float dot = velocity.Dot(tmpGravity); 
			velocity -= tmpGravity * dot; 
		}
		else
		{
			// 공중에 있을떄
			velocity += gravity * BxTime::DeltaTime();
		}		

		//최대 속도 제한
		Vector2 tmpGravity = gravity;
		tmpGravity.Normalize();
		float dot = velocity.Dot(tmpGravity);
		tmpGravity = tmpGravity * dot;

		Vector2 sideVelocity = velocity - tmpGravity;

		if (limVelocity.y < tmpGravity.Length())
		{
			tmpGravity.Normalize();
			tmpGravity *= limVelocity.y;
		}

		if (limVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= limVelocity.x;
		}

		velocity = tmpGravity + sideVelocity;


		if (!(velocity == Vector2::Zero))
		{
			//속도에 반대방향으로 마찰력 작용
			Vector2 tmpFriction = -velocity;		
			tmpFriction.Normalize();
			tmpFriction = tmpFriction * friction * mass * BxTime::DeltaTime();

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 큰 경우
			if (velocity.Length() <= tmpFriction.Length())
			{
				// 멈춰
				velocity = Vector2::Zero;
			}
			else
			{
				velocity += tmpFriction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = pos + velocity * BxTime::DeltaTime();
		tr->SetPos(pos);

		force = Vector2::One; 
	}

	void Rigidbody::LateUpdate()
	{}

	void Rigidbody::Render(HDC _hdc)
	{}

}

