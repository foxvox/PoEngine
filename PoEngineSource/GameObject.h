#pragma once 
#include "Component.h" 
#include "BxMath.h"

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

		virtual void Initialize(); 
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

		template <typename T> 
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize(); 
			comp->SetOwner(this); 

			components[(UINT)comp->GetType()] = comp; 	

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

		 

		void SetActive(bool _isActive)
		{
			if (_isActive == true)
				state = State::ACTIVE;
			else
				state = State::INACTIVE; 			
		}		 

		State	  GetState()					{ return state; }
		void	  SetDead()						{ state = State::DEAD; }
		bool	  IsActive()					{ return state == State::ACTIVE; }
		bool	  IsDead()						{ return state == State::DEAD; } 		
		LayerType GetLayerType()				{ return layerType; }
		void	  SetLayerType(LayerType _lt)   { layerType = _lt; }

	private: 
		State	  state; 
		LayerType layerType; 

		std::vector<Component*> components; 		
	};
}


