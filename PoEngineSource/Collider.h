#pragma once
#include "Component.h" 
#include "BxMath.h"

namespace Bx
{
	class Collider : public Component 
	{
	public:
		Collider(ColliderType _type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc); 

		virtual void OnCollisionEnter(Collider* rc);
		virtual void OnCollisionStay(Collider* rc);
		virtual void OnCollisionExit(Collider* rc);

		Vector2 GetOffset() { return offset; } 
		void	SetOffset(Vector2 _offset) { offset = _offset; } 
		UINT32  GetCID() { return cid; } 
		Vector2 GetSpan() { return span; }
		void    SetSpan(Vector2 _span) { span = _span; }
		ColliderType GetColliderType() { return type; }

	private:
		static UINT32	CID; 
		UINT32			cid; 
		Vector2			offset; 
		Vector2			span; 
		ColliderType	type; 
	};
}



