#pragma once 
#include "Component.h" 

namespace Bx
{
	typedef std::vector<Component*>::iterator COMPOITER;

	class GameObject
	{
	public:
		//friend static void Destroy(GameObject* _gameobj); //필요하면 friend를 맺을 수 있다. 

		enum class State
		{
			ACTIVE, 
			INACTIVE, 
			DEAD, 
			END
		};

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

			components[(size_t)comp->GetType()] = comp; 
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

		void InitTransform(); 

		State GetState() { return state; } 

		void SetActive(bool _isActive)
		{
			if (_isActive == true)
				state = State::ACTIVE;
			else
				state = State::INACTIVE; 			
		}		 

		void SetDead() { state = State::DEAD; }

	private: 
		State state; 
		std::vector<Component*> components; 
	};
}


