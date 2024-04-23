#include "PlayerScript.h" 
#include "Input.h" 
#include "Transform.h" 
#include "BxTime.h" 
#include "GameObject.h" 
#include "Animator.h"

namespace Bx
{
	PlayerScript::PlayerScript() 
		: state(PlayerScript::State::IDLE), animator(nullptr)
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
		case PlayerScript::State::IDLE:
			Idle(); 
			break;
		case PlayerScript::State::MOVE:
			Move(); 
			break;
		case PlayerScript::State::GIVEWATER:
			//GiveWater();
			break;
		case PlayerScript::State::SLEEP:
			break;
		case PlayerScript::State::ATTACK:
			break;
		default:
			break;
		}		
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC _hdc)
	{
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(KeyCode::LButton))
		{
			state = PlayerScript::State::MOVE;
			animator->PlayAnimation(L"RMove");

			Vector2 mousePos = Input::GetMousePos(); 
		}


		/*if (Input::GetKey(KeyCode::Right))
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
		}*/
	}

	void PlayerScript::Move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>(); 
		Vector2 pos = tr->GetPos(); 

		const float speed = 100.f;
		const float deltaTime = BxTime::DeltaTime();

		if (Input::GetKey(KeyCode::Right))
		{
			pos.x += speed * deltaTime;
		}		
		
		if (Input::GetKey(KeyCode::Left))
		{
			pos.x -= speed * deltaTime;
		}		
		
		if (Input::GetKey(KeyCode::Up))
		{
			pos.y -= speed * deltaTime;
		}		
		
		if (Input::GetKey(KeyCode::Down))
		{
			pos.y += speed * deltaTime;
		}

		tr->SetPos(pos); 


		if (Input::GetKeyUp(KeyCode::Right) || Input::GetKeyUp(KeyCode::Left) || 
			Input::GetKeyUp(KeyCode::Up) || Input::GetKeyUp(KeyCode::Down))
		{
			state = PlayerScript::State::IDLE;
			animator->PlayAnimation(L"Sit", false); 
		}
	}
}
