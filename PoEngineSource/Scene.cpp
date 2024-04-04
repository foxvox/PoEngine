#include "Scene.h" 

namespace Po
{
	Scene::Scene()
		: layers{} 
	{
		layers.resize((size_t)LayerType::Max);
		for (size_t i = 0; i < (size_t)LayerType::Max; i++)
		{
			layers[i] = new Layer(); 
		}

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


}