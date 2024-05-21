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
		// f(��) = m(����) x a(���ӵ�)
		// a = f / m;
		accel = force / mass;

		// �ӵ��� ���ӵ��� ���Ѵ�.
		velocity += accel * BxTime::DeltaTime();

		if (ground)
		{
			// ������ ������
			Vector2 tmpGravity = gravity;
			tmpGravity.Normalize();

			float dot = velocity.Dot(tmpGravity); 
			velocity -= tmpGravity * dot; 
		}
		else
		{
			// ���߿� ������
			velocity += gravity * BxTime::DeltaTime();
		}		

		//�ִ� �ӵ� ����
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
			//�ӵ��� �ݴ�������� ������ �ۿ�
			Vector2 tmpFriction = -velocity;		
			tmpFriction.Normalize();
			tmpFriction = tmpFriction * friction * mass * BxTime::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
			if (velocity.Length() <= tmpFriction.Length())
			{
				// ����
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

