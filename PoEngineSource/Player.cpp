#include "Player.h" 

namespace Bx
{
	void Player::Initialize()
	{
		GameObject::Initialize();  
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
