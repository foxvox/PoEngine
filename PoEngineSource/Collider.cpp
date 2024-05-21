#include "Collider.h"
#include "GameObject.h" 
#include "Script.h" 

namespace Bx
{
	UINT32 Collider::CID = 1;

	//span Vector2::Zero로 잡으면 scale을 곱할 때 적용이 안 됨.
	Collider::Collider(ColliderType _type)
		: Component(CompType::COLLIDER), cid(CID++), type(_type), 
		span(Vector2::One), offset(Vector2::Zero) 
	{}

	Collider::~Collider()
	{}

	void Collider::Initialize()
	{}

	void Collider::Update()
	{}
	
	void Collider::LateUpdate()
	{}
	
	void Collider::Render(HDC _hdc)
	{}

	void Collider::OnCollisionEnter(Collider * rc)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(rc);
	}

	void Collider::OnCollisionStay(Collider* rc)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(rc);
	}

	void Collider::OnCollisionExit(Collider* rc)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(rc);
	}
}