#include "BoxCollider2D.h" 
#include "GameObject.h" 
#include "Transform.h" 
#include "Renderer.h" 

namespace Bx
{
	BoxCollider2D::BoxCollider2D()
		: Collider(ColliderType::RECT2D)  
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
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

		if (mainCam)
			pos = mainCam->CalPos(pos); 

		Vector2 offset = GetOffset(); 

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH); 
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); 
		HPEN oldPen = (HPEN)SelectObject(_hdc, greenPen);
		::Rectangle(_hdc, pos.x + offset.x, pos.y + offset.y, 
			pos.x + offset.x + 100 * GetSpan().x, pos.y + offset.y + 100 * GetSpan().y);
		SelectObject(_hdc, oldBrush); 
		SelectObject(_hdc, oldPen);

		DeleteObject(greenPen); 
	}
}
