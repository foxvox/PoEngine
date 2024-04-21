#include "CatScript.h" 
#include "Input.h" 
#include "Transform.h" 
#include "Time.h" 
#include "GameObject.h" 
#include "Animator.h"

namespace Bx
{
	CatScript::CatScript()
		: state(CatScript::State::SIT), animator(nullptr)
	{
	}

	CatScript::~CatScript()
	{
	}

	void CatScript::Init()
	{
	}

	void CatScript::Update()
	{
		if (animator == nullptr)
		{
			animator = GetOwner()->GetComponent<Animator>();
		}

		switch (state)
		{
		case CatScript::State::SIT:
			Sit();
			break;
		case CatScript::State::MOVE:
			Move();
			break;
		case CatScript::State::SLEEP:
			break;
		case CatScript::State::ATTACK:
			break;
		default:
			break;
		}
	}

	void CatScript::LateUpdate()
	{
	}

	void CatScript::Render(HDC _hdc)
	{
	}

	void CatScript::Sit()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			state = CatScript::State::MOVE;
			animator->PlayAnimation(L"RMove");
		}
		
		if (Input::GetKey(KeyCode::Left))
		{
			state = CatScript::State::MOVE;
			animator->PlayAnimation(L"LMove");
		}
		
		if (Input::GetKey(KeyCode::Up))
		{
			state = CatScript::State::MOVE;
			animator->PlayAnimation(L"UMove");
		}
		
		if (Input::GetKey(KeyCode::Down))
		{
			state = CatScript::State::MOVE;
			animator->PlayAnimation(L"DMove");
		}
	}

	void CatScript::Move()
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
			state = CatScript::State::SIT;
			animator->PlayAnimation(L"Sit", false);
		}
	}
}
