#include "Transform.h"

namespace Bx
{
	Transform::Transform()
		: Component(CompType::TRANS), position(Vector2::zero), scale(Vector2::one), rotation(0.f)
	{}

	Transform::~Transform()
	{}

	void Transform::Initialize()
	{}

	void Transform::Update()
	{}

	void Transform::LateUpdate()
	{}

	void Transform::Render(HDC _hdc)
	{}
}
