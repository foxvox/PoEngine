#include "Rigidbody.h"
#include "BxTime.h"
#include "Transform.h"
#include "GameObject.h"

namespace Bx
{
	Rigidbody::Rigidbody()
		: Component(CompType::RIGIDBODY), ground(false), mass(1.f), friction(100.f), 
		force(Vector2::zero), velocity(Vector2::zero), limVelocity(Vector2(200.f, 1000.f)), 
		gravity(Vector2(0.f, 800.f)), accel(Vector2::zero) 
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


		if (!(velocity == Vector2::zero))
		{
			//�ӵ��� �ݴ�������� ������ �ۿ�
			Vector2 friction = -velocity;
			friction = friction.Normalize() * friction * mass * BxTime::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
			if (velocity.Length() <= friction.Length())
			{
				// ����
				velocity = Vector2::zero;
			}
			else
			{
				velocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = pos + velocity * BxTime::DeltaTime();
		tr->SetPos(pos);

		force.Clear();
	}

	void Rigidbody::LateUpdate()
	{}

	void Rigidbody::Render(HDC _hdc)
	{}

}

