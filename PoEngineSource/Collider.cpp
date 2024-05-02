#include "Collider.h"

namespace Bx
{
	Collider::Collider()
		: Component(CompType::COLLIDER)
	{}

	Collider::~Collider()
	{}

	void Collider::Init()
	{}

	void Collider::Update()
	{}
	
	void Collider::LateUpdate()
	{}
	
	void Collider::Render(HDC _hdc)
	{}
}