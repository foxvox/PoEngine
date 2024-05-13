#include "CameraScript.h" 
#include "Input.h"
#include "Transform.h"
#include "BxTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "Cat.h"
#include "CatScript.h"
#include "Object.h"
#include "Resources.h"

namespace Bx
{
	CameraScript::CameraScript()
	{}

	CameraScript::~CameraScript()
	{}

	void CameraScript::Initialize()
	{
	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(KeyCode::Right))
		{
			pos.x += 100.f * BxTime::DeltaTime();
		}
		if (Input::GetKey(KeyCode::Left))
		{
			pos.x -= 100.f * BxTime::DeltaTime();
		}
		if (Input::GetKey(KeyCode::Up))
		{
			pos.y -= 100.f * BxTime::DeltaTime();
		}
		if (Input::GetKey(KeyCode::Down))
		{
			pos.y += 100.f * BxTime::DeltaTime();
		}

		tr->SetPos(pos);
	}

	void CameraScript::LateUpdate()
	{
	}

	void CameraScript::Render(HDC hdc)
	{
	}

}

