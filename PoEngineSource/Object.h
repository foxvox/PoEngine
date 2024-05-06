#pragma once 
#include "Component.h"
#include "GameObject.h" 
#include "Layer.h" 
#include "SceneMgr.h" 
#include "Scene.h" 

namespace Bx  
{
	template<typename T> 
	static T* Instantiate(LayerType _type)   
	{
		T* gameObj = new T(); 
		Scene* activeScene = SceneMgr::GetActiveScene(); 
		Layer* layer = activeScene->GetLayer(_type); 
		layer->AddGameObject(gameObj); 

		return gameObj; 
	} 

	template<typename T>
	static T* Instantiate(LayerType _type, Vector2 _pos)
	{
		T* gameObj = new T();
		Scene* activeScene = SceneMgr::GetActiveScene();
		Layer* layer = activeScene->GetLayer(_type);
		layer->AddGameObject(gameObj);

		Transform* tr = gameObj->GetComponent<Transform>(); 
		tr->SetPos(_pos);  

		return gameObj;
	}

	static void DontDestroyOnLoad(GameObject* gameObj)
	{
		Scene* activeScene = SceneMgr::GetActiveScene();
		// 현재씬에서 게임오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObj);

		// 해당 게임오브젝트를 DontDestroy씬으로 넣어준다.
		Scene* ddolScene = SceneMgr::GetDDOLScene();
		ddolScene->AddGameObject(gameObj, gameObj->GetLayerType()); 
	}
}
