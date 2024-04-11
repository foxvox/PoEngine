#include "PlayerScript.h" 
#include "Input.h" 
#include "Transform.h" 
#include "Time.h" 
#include "GameObject.h" 

namespace Bx
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Init()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x += 100.0f * Time::GetDeltaTime();
			tr->SetPos(pos);
		}

		if (Input::GetKey(KeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x -= 100.0f * Time::GetDeltaTime();
			tr->SetPos(pos);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC _hdc)
	{
	}
}
