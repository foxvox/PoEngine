#include "Camera.h" 
#include "Transform.h" 
#include "App.h" 

extern Bx::App app; 

namespace Bx
{
	Camera::Camera() 
		: Component(CompType::CAMERA), target(nullptr) 
	{}

	Camera::~Camera()
	{}

	void Camera::Init()
	{
		resolution.x = (float)app.GetWidth(); 
		resolution.y = (float)app.GetHeight(); 
	}

	void Camera::Update()
	{
		if (target)
		{
			Transform* tr = target->GetComponent<Transform>(); 
			destPos = tr->GetPos(); 
		}
		else
		{
			//GetOwner�� ���� ���ӿ�����Ʈ �ν��Ͻ��� �����´�. 
			Transform* camTr = GetOwner()->GetComponent<Transform>();
			destPos = camTr->GetPos();
		}

		Vector2 halfResolution = resolution / 2.f; 
		relativePos = destPos - halfResolution; 
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC _hdc)
	{
	}
}
