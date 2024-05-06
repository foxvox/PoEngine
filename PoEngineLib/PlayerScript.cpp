#include "PlayerScript.h" 
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
	PlayerScript::PlayerScript() 
		: state(PlayerScript::State::IDLE), animator(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
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
			GiveWater();
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
	{}

	//Animation Render 함수에서 처리한다.
	void PlayerScript::Render(HDC _hdc)
	{}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(KeyCode::LButton))
		{
			Cat* cat = Instantiate<Cat>(LayerType::ANIMAL);			
			CatScript* cs = cat->AddComponent<CatScript>();
			cs->SetPlayer(GetOwner());

			Texture* catx = Resources::Find<Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();

			//카메라가 타겟을 쫒아가게 설정
			//camComp->SetTarget(cat);

			catAnimator->CreateAnimation(L"DMove", catx, Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"RMove", catx, Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"UMove", catx, Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"LMove", catx, Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"Sit", catx, Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"Grooming", catx, Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
			catAnimator->CreateAnimation(L"LayDown", catx, Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);			
			catAnimator->PlayAnimation(L"Sit", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			cat->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));
			cat->GetComponent<Transform>()->SetPos(tr->GetPos());

			Vector2 mousePos = Input::GetMousePos();
			cs->dest = mousePos;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(KeyCode::Right))
		{
			state = PlayerScript::State::MOVE; 
			//animator->PlayAnimation(L"RMove"); 
		}
		
		if (Input::GetKey(KeyCode::Left))
		{
			state = PlayerScript::State::MOVE;
			//animator->PlayAnimation(L"LMove");
		}
		
		if (Input::GetKey(KeyCode::Up))
		{
			state = PlayerScript::State::MOVE;
			//animator->PlayAnimation(L"UMove");
		}
		
		if (Input::GetKey(KeyCode::Down))
		{
			state = PlayerScript::State::MOVE;
			//animator->PlayAnimation(L"DMove");
		}

		tr->SetPos(pos); 
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
			animator->PlayAnimation(L"Idle", false); 
		}
	}

	void PlayerScript::GiveWater()
	{
		/*Animation* fgwani = animator->FindAnimation(L"FrontGiveWater");
		Animation* activeAni = animator->GetActiveAnimation(); */
		bool isAniComplete = animator->IsAnimationComplete(); 

		if (/*fgwani == activeAni &&*/ isAniComplete)
		{
			state = State::IDLE; 
			animator->PlayAnimation(L"Idle", false); 
		}		
	}
	void PlayerScript::AttackEffect() 
	{
		Cat* cat = Instantiate<Cat>(LayerType::ANIMAL);
		//cat->SetActive(true); 
		CatScript* cs = cat->AddComponent<CatScript>();
		cs->SetPlayer(GetOwner()); 

		Texture* catx = Resources::Find<Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();

		//카메라가 타겟을 쫒아가게 설정
		//camComp->SetTarget(cat);

		catAnimator->CreateAnimation(L"DMove", catx, Vector2(0.f, 0.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"RMove", catx, Vector2(0.f, 32.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"UMove", catx, Vector2(0.f, 64.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LMove", catx, Vector2(0.f, 96.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"Sit", catx, Vector2(0.f, 128.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"Grooming", catx, Vector2(0.f, 160.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LayDown", catx, Vector2(0.f, 192.f), Vector2(32.f, 32.f), Vector2::zero, 4, 0.2f);
		catAnimator->PlayAnimation(L"Sit", false);

		Transform* tr = GetOwner()->GetComponent<Transform>(); 

		cat->GetComponent<Transform>()->SetScale(Vector2(2.f, 2.f));
		cat->GetComponent<Transform>()->SetPos(tr->GetPos());

		Vector2 mousePos = Input::GetMousePos();
		cs->dest = mousePos; 
	}

	void PlayerScript::OnCollisionEnter(Collider* rc)
	{
		rc->GetOwner()->GetComponent<Transform>()->SetPos(Vector2(400.f, 500.f)); 
	}

	void PlayerScript::OnCollisionStay(Collider* rc)
	{
		int a = 0; 
	}

	void PlayerScript::OnCollisionExit(Collider* rc)
	{
		int a = 0; 
	}
}
