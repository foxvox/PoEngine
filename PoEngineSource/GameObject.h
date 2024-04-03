#pragma once 
#include "Input.h" 
#include "Component.h" 

namespace Po
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Init(); 
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

		template <typename T> 
		T* AddComponent()
		{
			T* comp = new T();
			comp->Init(); 
			comp->SetOwner(this); 
			components.push_back(comp); 

			return comp; 
		}
		
		template <typename T> 
		T* GetComponent()
		{
			T* component = nullptr; 
			for (Component* comp : components)
			{
				component = dynamic_cast<T*>(comp); 
				if (component)
					break; 
			}

			return component; 
		}		

		/*
		void SetPos(float _x, float _y)
		{
			x = _x; 
			y = _y; 
		}
		

		float GetPosX() const { return x; } 
		float GetPosY() const { return y; }
		*/

	private: 
		std::vector<Component*> components; 

		/*
		float x; 
		float y; 
		*/
	};
}


