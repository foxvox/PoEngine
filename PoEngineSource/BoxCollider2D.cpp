#include "BoxCollider2D.h" 
#include "GameObject.h" 
#include "Transform.h" 

namespace Bx
{
	BoxCollider2D::BoxCollider2D()
		: Collider() 
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Init()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC _hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>(); 
		Vector2 pos = tr->GetPos(); 

		Vector2 offset = GetOffset(); 
		HBRUSH tb = (HBRUSH)GetStockObject(NULL_BRUSH); 
		HBRUSH ob = (HBRUSH)SelectObject(_hdc, tb);
		
		Rectangle(_hdc, pos.x + offset.x, pos.y + offset.y, pos.x + offset.x + 100, pos.y + offset.y + 100); 

		SelectObject(_hdc, ob); 
	}
}
