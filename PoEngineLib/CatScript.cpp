#include "CatScript.h" 
#include "Input.h" 
#include "BxTime.h" 
#include "GameObject.h" 
#include "Animator.h"

namespace Bx
{
	CatScript::CatScript()
		: state(CatScript::State::SIT), animator(nullptr), 
		catTime(0.f), direction(CatScript::Dir::DOWN)
	{}

	CatScript::~CatScript()
	{}

	void CatScript::Init()
	{}

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
	{}

	void CatScript::Render(HDC _hdc)
	{}

	void CatScript::Sit()
	{
		catTime += BxTime::DeltaTime(); 
		if (catTime > 4.f)
		{
			state = CatScript::State::MOVE; 			
			direction = (Dir)(rand() % 4); 
			AniByMovingDir(direction); 
			catTime = 0.f;
		}	
	}

	void CatScript::Move()
	{
		catTime += BxTime::DeltaTime(); 
		if (catTime > 2.f)
		{
			int isLayDown = rand() % 2; 
			if (isLayDown)
			{
				state = State::LAYDOWN;
				animator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				state = State::SIT;
				animator->PlayAnimation(L"Sit", false);
			}			
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		CatMoving(tr); 			
	}

	void CatScript::AniByMovingDir(Dir _dir)
	{
		switch (_dir)
		{
		case CatScript::Dir::LEFT:
			animator->PlayAnimation(L"LMove");
			break;
		case CatScript::Dir::RIGHT:
			animator->PlayAnimation(L"RMove");
			break;
		case CatScript::Dir::UP:
			animator->PlayAnimation(L"UMove");
			break;
		case CatScript::Dir::DOWN:
			animator->PlayAnimation(L"DMove");
			break;
		default:
			assert(false);
			break;
		}
	}

	void CatScript::CatMoving(Transform* _tr)
	{
		Vector2 pos = _tr->GetPos();

		const float speed = 50.f;

		/*if (BxTime::DeltaTime() > 1.f)
			return;*/ 
		
		switch (direction)
		{
		case CatScript::Dir::LEFT:
			pos.x -= speed * BxTime::DeltaTime();
			break;
		case CatScript::Dir::RIGHT:
			pos.x += speed * BxTime::DeltaTime();
			break;
		case CatScript::Dir::UP:
			pos.y -= speed * BxTime::DeltaTime();
			break;
		case CatScript::Dir::DOWN:
			pos.y += speed * BxTime::DeltaTime();
			break;
		default:
			assert(false); 
			break;
		}

		_tr->SetPos(pos);
	}

	void CatScript::LayDown()
	{}
}
