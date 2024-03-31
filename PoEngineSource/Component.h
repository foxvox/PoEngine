#pragma once
#include "Entity.h" 

namespace Po
{
	class GameObject; 

	class Component : public Entity
	{
	public:
		Component(); 
		~Component(); 

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

		void SetOwner(GameObject* _owner) {	owner = _owner; }
		GameObject* GetOwner() const { return owner; } 

	private:
		GameObject* owner; 
	};
}



