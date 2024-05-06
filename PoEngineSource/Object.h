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
		// ��������� ���ӿ�����Ʈ�� �����ش�.
		activeScene->EraseGameObject(gameObj);

		// �ش� ���ӿ�����Ʈ�� DontDestroy������ �־��ش�.
		Scene* ddolScene = SceneMgr::GetDDOLScene();
		ddolScene->AddGameObject(gameObj, gameObj->GetLayerType()); 
	}
}
