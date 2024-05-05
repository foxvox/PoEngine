#pragma once 
#include "Entity.h" 
//#include "CommonInclude.h" 
#include "GameObject.h" 
 
namespace Bx  
{
	typedef std::vector<GameObject*>::iterator GAMEOBJITER; 

	class Layer : public Entity 
	{
	public:
		Layer();
		~Layer(); 

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* _gameObj);

		const std::vector<GameObject*> GetGameObjects() { return gameObjs; }

		void FindDeadGameObjs(OUT std::vector<GameObject*>& _gameObjs);
		void DelGameObjs(std::vector<GameObject*> _gameObjs);
		void EraseGameObjs();

	private:
		//LayerType type; 
		std::vector<GameObject*> gameObjs;
	};
}



