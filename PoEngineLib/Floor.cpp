#include "Floor.h"
#include "Cat.h"
#include "Input.h"
#include "Transform.h"
#include "BxTime.h"

namespace Bx
{
	Floor::Floor()
	{
	}
	Floor::~Floor()
	{
	}
	void Floor::Initialize()
	{
		GameObject::Initialize();
	}

	void Floor::Update()
	{
		GameObject::Update();
	}

	void Floor::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Floor::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}
