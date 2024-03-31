#include "Scene.h" 

namespace Po
{
	Scene::Scene()
		: gameObjects{} 
	{}
	Scene::~Scene()
	{}

	void Scene::Init()
	{
		for (int i = 0; i < 1; i++)
		{
			GameObject* pGameObj = new GameObject();
			pGameObj->SetPos(rand() % 1600, rand() % 900);
			gameObjects.push_back(pGameObj);
		}
	}

	void Scene::Update()
	{
		for (GameObject* gameObj : gameObjects)
		{
			gameObj->Update(); 
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : gameObjects)
		{
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC _hdc)
	{
		for (GameObject* gameObj : gameObjects)
		{
			gameObj->Render(_hdc);
		}
	}

	void Scene::AddGameObject(GameObject* _gameObject)
	{
		gameObjects.push_back(_gameObject); 
	}
}