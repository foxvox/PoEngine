#include "Player.h" 
#include "Input.h" 
#include "Transform.h" 
#include "Time.h" 

namespace Bx
{
	Player::Player()
	{}

	Player::~Player()
	{}

	void Player::Init()
	{
		GameObject::Init(); 
	}

	void Player::Update()
	{
		GameObject::Update(); 
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate(); 

		if (Input::GetKey(KeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>(); 
			Vector2 pos = tr->GetPos(); 
			pos.x += 100.0f * Time::GetDeltaTime(); 
			tr->SetPos(pos); 
		}
	}

	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc); 
	}
}
