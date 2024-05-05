#include "CatScript.h" 
#include "Input.h" 
#include "BxTime.h" 
#include "GameObject.h" 
#include "Animator.h" 
#include "BxMath.h" 
#include "Object.h" 

namespace Bx
{
	CatScript::CatScript()
		: state(CatScript::State::SIT), animator(nullptr), 
		catTime(0.f), direction(CatScript::Dir::DOWN), activeTime(0.f), 
		player(nullptr), dest(Vector2::zero), radian(0.f)
	{}

	CatScript::~CatScript()
	{}

	void CatScript::Init()
	{}

	void CatScript::Update()
	{
		activeTime += BxTime::DeltaTime(); 
		if (activeTime > 7.f)
		{}

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

		/*if (catTime > 4.f) 
		{
			Destroy(GetOwner()); 
		}*/

		Transform* tr = GetOwner()->GetComponent<Transform>(); 
		Vector2 pos = tr->GetPos(); 

		//player 위치에서 start하고 싶을 때
		/*pos.y = playerPos.y;
		tr->SetPos(pos);*/

		//Vector2 mousePos = Input::GetMousePos(); 
		//마우스 위치 이동 (벡터의 뺄셈 활용) 		 		
		/*Transform* playerTr = player->GetComponent<Transform>(); 
		Vector2 playerPos = playerTr->GetPos(); 
		Vector2 destDir = dest - playerPos; 
		destDir.Normalize(); 
		pos += destDir * (100.f * BxTime::DeltaTime());
		float dotVal = destDir.Dot(Vector2::right); 
		float rotRad = acosf(dotVal); 
		float rotDeg = RadToDeg(rotRad);*/  

		//삼각함수를 통한 이동 
		/*radian += 4.f * BxTime::DeltaTime();
		pos.x += 100.f * BxTime::DeltaTime(); 
		pos.y -= 100.f * abs(sinf(radian)) * (100.f * BxTime::DeltaTime()); */
		
		//tr->SetPos(pos); 		

		/*if (catTime > 2.f) 
		{
			state = CatScript::State::MOVE; 			
			direction = (Dir)(rand() % 4); 
			AniByMovingDir(direction); 
			catTime = 0.f;
		}*/	
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
