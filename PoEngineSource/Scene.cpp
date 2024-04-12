#include "Scene.h" 

namespace Bx
{
	Scene::Scene()
		: layers{} 
	{
		CreateLayers(); 
	}

	Scene::~Scene()
	{}

	void Scene::Init()
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->Init();
		}
	}

	void Scene::Update() 
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC _hdc)
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(_hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{		
	}

	void Scene::AddGameObject(GameObject* _gameObj, LayerType _type)
	{
		layers[(size_t)_type]->AddGameObject(_gameObj); 
	}

	void Scene::CreateLayers()
	{
		layers.resize((size_t)LayerType::MAX);
		for (size_t i = 0; i < (size_t)LayerType::MAX; i++)
		{
			layers[i] = new Layer();
		}
	}
}