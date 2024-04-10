#include "Transform.h"

namespace Bx
{
	Transform::Transform()
		: Component(CompType::TRANS), position{} 
	{}

	Transform::~Transform()
	{}

	void Transform::Init()
	{}

	void Transform::Update()
	{}

	void Transform::LateUpdate()
	{}

	void Transform::Render(HDC _hdc)
	{}
}
