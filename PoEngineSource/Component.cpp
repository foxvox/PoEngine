#include "Component.h" 

namespace Bx
{
	Component::Component(CompType _compType) 
		: compType(_compType), owner(nullptr) 
	{}

	Component::~Component()
	{}

	void Component::Initialize()
	{}

	void Component::Update()
	{}

	void Component::LateUpdate()
	{}

	void Component::Render(HDC _hdc)
	{}
}
