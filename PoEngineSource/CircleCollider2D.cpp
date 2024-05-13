#include "CircleCollider2D.h" 
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Camera.h"

namespace Bx
{
	CircleCollider2D::CircleCollider2D()
		: Collider(ColliderType::CIRCLE2D), radius(1.f) 
	{
	}
	CircleCollider2D::~CircleCollider2D()
	{
	}
	void CircleCollider2D::Initialize()
	{
	}
	void CircleCollider2D::Update()
	{
	}
	void CircleCollider2D::LateUpdate()
	{
	}
	void CircleCollider2D::Render(HDC _hdc) 
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

		Vector2 rBtm;
		rBtm.x = pos.x + offset.x + 100 * GetSpan().x;
		rBtm.y = pos.y + offset.y + 100 * GetSpan().y;

		Ellipse(_hdc, pos.x + offset.x, pos.y + offset.y, rBtm.x, rBtm.y); 

		SelectObject(_hdc, oldBrush);
		SelectObject(_hdc, oldPen);
		DeleteObject(greenPen);
	}
}
