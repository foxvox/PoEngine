#include "Layer.h"

namespace Bx
{
	Layer::Layer() 
		: gameObjs{} 
	{}

	Layer::~Layer()
	{
		for (GameObject* gameObj : gameObjs)
		{
			if (gameObj == nullptr)
				continue; 			

			delete gameObj; 
			gameObj = nullptr; 
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : gameObjs)
		{
			if (gameObj == nullptr)
				continue; 

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : gameObjs)
		{
			if (gameObj == nullptr)
				continue;
						
			if (gameObj->IsActive() == false) 
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : gameObjs)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC _hdc)
	{
		for (GameObject* gameObj : gameObjs)
		{
			if (gameObj == nullptr)
				continue; 

			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(_hdc); 
		}
	}

	void Layer::Destroy()
	{
		std::vector<GameObject*> delGameObjs{};
		FindDeadGameObjs(delGameObjs);
		EraseDeadGameObjs(); 
		DelGameObjs(delGameObjs);		
	}

	void Layer::AddGameObj(GameObject* _gameObj)
	{
		if (_gameObj == nullptr)
			return; 

		gameObjs.push_back(_gameObj);
	}

	void Layer::FindDeadGameObjs(OUT std::vector<GameObject*>& _gameObjs)
	{
		for (GameObject* obj : gameObjs)
		{
			GameObject::State state = obj->GetState();
			if (state == GameObject::State::DEAD)
				_gameObjs.push_back(obj);
		}
	}

	void Layer::EraseGameObj(GameObject* _gameObj)
	{
		//¶÷´ÙÆã¼Ç 
		std::erase_if(gameObjs,
			[=](GameObject* gameObj)
			{
				return gameObj == _gameObj;
			});
	}

	void Layer::EraseDeadGameObjs()
	{
		std::erase_if(gameObjs,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}

	void Layer::DelGameObjs(std::vector<GameObject*> _gameObjs)
	{
		for (GameObject* obj : _gameObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}
}

