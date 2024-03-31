#pragma once
#include "Entity.h" 
#include "GameObject.h" 

namespace Po
{
	class Scene : public Entity 
	{
	public:
		Scene();
		~Scene(); 

		//void SetName(const std::wstring& _name) ���
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hdc);

		void AddGameObject(GameObject* _gameObject); 

	private:
		//std::wstring name; ��� 
		std::vector<GameObject*> gameObjects; 
	};
}

