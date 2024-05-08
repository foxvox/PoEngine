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

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);
		virtual void Destroy();

		void AddGameObj(GameObject* _gameObj);
		void EraseGameObj(GameObject* _gameObj);

		const std::vector<GameObject*> GetGameObjs() { return gameObjs; }

		void FindDeadGameObjs(OUT std::vector<GameObject*>& _gameObjs);
		void DelGameObjs(std::vector<GameObject*> _gameObjs);
		void EraseDeadGameObjs();
				

	private:
		//LayerType type; 
		std::vector<GameObject*> gameObjs;
	};
}



