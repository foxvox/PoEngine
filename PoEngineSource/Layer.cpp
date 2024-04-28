#include "Layer.h"

namespace Bx
{
	Layer::Layer() 
		: gameObjects{} 
	{}

	Layer::~Layer()
	{
		for (GameObject* gameObj : gameObjects)
		{
			if (gameObj == nullptr)
				continue; 

			delete gameObj; 
			gameObj = nullptr; 
		}
	}

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

	void Layer::Destroy()
	{
		for (GAMEOBJITER iter = gameObjects.begin(); iter != gameObjects.end(); )  
		{
			GameObject::State state = (*iter)->GetState(); 
			if (state == GameObject::State::DEAD)
			{
				GameObject* deadObj = (*iter); 

				//vector class�� erase ����Լ��� ����ϱ� ���� iter�� ����� �� �ְ� �ߴ�. 
				//����! iter�� ����Ű�� GameObject* �� �����Ǹ� iter�� �ڵ����� ���� ���Ҹ� ����Ű�� �ȴ�. 
				iter = gameObjects.erase(iter);

				delete deadObj; 
				deadObj = nullptr; 

				continue; 
			}

			iter++; 
		}
	}

	void Layer::AddGameObject(GameObject* _gameObj)
	{
		if (_gameObj == nullptr)
			return; 

		gameObjects.push_back(_gameObj);
	}
}

