#include "Layer.h"

namespace Po
{
	Layer::Layer() 
		: gameObjects{} 
	{}

	Layer::~Layer()
	{}

	void Layer::Init()
	{
		for (GameObject* gameObj : gameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Init();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : gameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : gameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC _hdc)
	{
		for (GameObject* gameObj : gameObjects)
		{
			if (gameObj == nullptr)
				continue; 

			gameObj->Render(_hdc); 
		}
	}

	void Layer::AddGameObject(GameObject* _gameObj)
	{
		if (_gameObj == nullptr)
			return; 

		gameObjects.push_back(_gameObj);
	}
}

