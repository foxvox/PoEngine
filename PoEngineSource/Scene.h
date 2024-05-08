#pragma once
#include "Entity.h" 
#include "GameObject.h" 
#include "Layer.h" 

namespace Bx
{
	class Scene : public Entity 
	{
	public:
		Scene();
		~Scene();

		//void SetName(const std::wstring& _name) 상속
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);	
		virtual void Destroy(); 

		virtual void OnEnter();
		virtual void OnExit(); 

		void	AddGameObj(GameObject* _gameObj, LayerType _type); 
		void	EraseGameObj(GameObject* _gameObj);				
		void	CreateLayers(); 
		Layer*  GetLayer(const LayerType _type) { return layers[(UINT)_type]; }

	private:
		//std::wstring name; 상속 
		std::vector<Layer*> layers; 
	};
}

