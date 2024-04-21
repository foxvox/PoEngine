#include "Cat.h" 
#include "Input.h" 
#include "Transform.h" 
#include "BxTime.h" 

namespace Bx
{
	Cat::Cat()
	{}

	Cat::~Cat()
	{}

	void Cat::Init()
	{
		GameObject::Init();
	}

	void Cat::Update()
	{
		GameObject::Update();
	}

	void Cat::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Cat::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}