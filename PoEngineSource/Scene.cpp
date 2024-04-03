#include "Scene.h" 

namespace Po
{
	Scene::Scene()
		: gameObjects{} 
	{}
	Scene::~Scene()
	{}

	void Scene::Init()
	{}

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

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* _gameObject)
	{
		gameObjects.push_back(_gameObject); 
	}
}