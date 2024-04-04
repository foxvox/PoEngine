#pragma once 
#include "Entity.h" 
#include "CommonInclude.h" 
#include "GameObject.h" 
 
namespace Po  
{
	class Layer : public Entity 
	{
	public:
		Layer();
		~Layer(); 
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc); 

		void AddGameObject(GameObject* _gameObj);

	private:
		//LayerType type; 
		std::vector<GameObject*> gameObjects;
	};
}



