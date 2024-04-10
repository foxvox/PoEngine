#pragma once
#include "Entity.h" 

namespace Bx
{
	class GameObject; 

	class Component : public Entity
	{
	public:
		Component(CompType _compType); 
		virtual ~Component(); 

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

		void SetOwner(GameObject* _owner) {	owner = _owner; }
		GameObject* GetOwner() const { return owner; } 
		CompType GetType() const { return compType; } 

	private:
		GameObject* owner; 
		CompType	compType; 
	};
}



