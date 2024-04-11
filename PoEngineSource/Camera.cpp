#include "Camera.h" 
#include "Transform.h" 

namespace Bx
{
	Camera::Camera() 
		: Component(CompType::CAMERA), 
		relativePos(Vector2::zero), 
		destPos(Vector2::zero),
		resolution(Vector2(1600.f, 900.f)), 		
		target(nullptr) 
	{}
	Camera::~Camera()
	{
	}
	void Camera::Init()
	{
	}
	void Camera::Update()
	{
		if (target)
		{
			Transform* tr = target->GetComponent<Transform>(); 
			destPos = tr->GetPos(); 
		}

		relativePos = destPos - (resolution / 2.0); 
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC _hdc)
	{
	}
}
