#include "FloorScript.h"

#include "CatScript.h"
#include "Input.h"
#include "Transform.h"
#include "BxTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"

namespace Bx
{
	FloorScript::FloorScript()
	{}

	FloorScript::~FloorScript()
	{}

	void FloorScript::Initialize()
	{}

	void FloorScript::Update()
	{}

	void FloorScript::LateUpdate()
	{}

	void FloorScript::Render(HDC hdc)
	{}

	void FloorScript::OnCollisionEnter(Collider* rc)
	{
		Rigidbody* plrb = rc->GetOwner()->GetComponent<Rigidbody>();
		Transform* pltr = rc->GetOwner()->GetComponent<Transform>();
		Collider* plc = rc;

		Rigidbody* flrb = this->GetOwner()->GetComponent<Rigidbody>();
		Transform* fltr = this->GetOwner()->GetComponent<Transform>();
		Collider* flc = this->GetOwner()->GetComponent<Collider>();


		float len = fabs(pltr->GetPos().y - fltr->GetPos().y);
		float scale = fabs(plc->GetSpan().y * 100 / 2.0f - flc->GetSpan().y * 100 / 2.0f);

		if (len < scale)
		{
			Vector2 playerPos = pltr->GetPos();
			playerPos.y -= (scale - len) - 1.0f;

			pltr->SetPos(playerPos);
		}

		plrb->SetGround(true);
	}

	void FloorScript::OnCollisionStay(Collider* other)
	{}

	void FloorScript::OnCollisionExit(Collider* other)
	{}
}
