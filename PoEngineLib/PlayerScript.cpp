#include "PlayerScript.h" 
#include "Input.h" 
#include "Transform.h" 
#include "Time.h" 
#include "GameObject.h" 
#include "Animator.h"

namespace Bx
{
	PlayerScript::PlayerScript() 
		: state(PlayerScript::State::SIT), animator(nullptr)
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
		if (animator == nullptr)
		{
			animator = GetOwner()->GetComponent<Animator>(); 
		}

		switch (state)
		{
		case PlayerScript::State::SIT:
			Sit(); 
			break;
		case PlayerScript::State::MOVE:
			Move(); 
			break;
		case PlayerScript::State::SLEEP:
			break;
		case PlayerScript::State::ATTACK:
			break;
		default:
			break;
		}

		/*if (Input::GetKey(KeyCode::Right))
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

		if (Input::GetKey(KeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y -= 100.0f * Time::GetDeltaTime();
			tr->SetPos(pos);
		}

		if (Input::GetKey(KeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y += 100.0f * Time::GetDeltaTime();
			tr->SetPos(pos);
		}*/	
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC _hdc)
	{
	}

	void PlayerScript::Sit()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			state = PlayerScript::State::MOVE; 
			animator->PlayAnimation(L"RMove"); 
		}
		
		if (Input::GetKey(KeyCode::Left))
		{
			state = PlayerScript::State::MOVE;
			animator->PlayAnimation(L"LMove");
		}
		
		if (Input::GetKey(KeyCode::Up))
		{
			state = PlayerScript::State::MOVE;
			animator->PlayAnimation(L"UMove");
		}
		
		if (Input::GetKey(KeyCode::Down))
		{
			state = PlayerScript::State::MOVE;
			animator->PlayAnimation(L"DMove");
		}
	}

	void PlayerScript::Move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>(); 
		Vector2 pos = tr->GetPos(); 

		if (Input::GetKey(KeyCode::Right))
		{
			pos.x += 100.f * Time::GetDeltaTime(); 
		}		
		
		if (Input::GetKey(KeyCode::Left))
		{
			pos.x -= 100.f * Time::GetDeltaTime();
		}		
		
		if (Input::GetKey(KeyCode::Up))
		{
			pos.y -= 100.f * Time::GetDeltaTime();
		}		
		
		if (Input::GetKey(KeyCode::Down))
		{
			pos.y += 100.f * Time::GetDeltaTime();
		}

		tr->SetPos(pos); 


		if (Input::GetKeyUp(KeyCode::Right) || Input::GetKeyUp(KeyCode::Left) || 
			Input::GetKeyUp(KeyCode::Up) || Input::GetKeyUp(KeyCode::Down))
		{
			state = PlayerScript::State::SIT;
			animator->PlayAnimation(L"Sit", false); 
		}
	}
}
