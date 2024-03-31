#include "Player.h" 

namespace Po
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
	}

	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc); 
	}
}
