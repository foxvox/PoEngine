#include "Scene.h" 
#include "CollisionMgr.h" 

namespace Bx
{
	Scene::Scene()
		: layers{} 
	{
		CreateLayers(); 
	}

	Scene::~Scene()
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue; 

			delete layer; 
			layer = nullptr; 
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
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

	void Scene::Destroy()
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::OnEnter()
	{}

	void Scene::OnExit()
	{
		CollisionMgr::Clear(); 
	}

	void Scene::AddGameObj(GameObject* _gameObj, LayerType _type)
	{
		layers[(size_t)_type]->AddGameObj(_gameObj); 
	}

	void Scene::EraseGameObj(GameObject* _gameObj)
	{
		LayerType layerType = _gameObj->GetLayerType();
		layers[(UINT)layerType]->EraseGameObj(_gameObj);
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