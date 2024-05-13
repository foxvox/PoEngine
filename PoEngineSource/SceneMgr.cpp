#include "SceneMgr.h" 
#include "DontDestroyOnLoad.h" 

namespace Bx
{
	std::map<std::wstring, Scene*> SceneMgr::scenes{}; 
	Scene* SceneMgr::activeScene = nullptr; 
	Scene* SceneMgr::ddolScene = nullptr; 

	Scene* SceneMgr::LoadScene(const std::wstring& _name)
	{
		if (activeScene)
			activeScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = scenes.find(_name);

		if (iter == scenes.end())
			return nullptr;

		activeScene = iter->second;
		activeScene->OnEnter();

		return activeScene;
	}

	std::vector<GameObject*> SceneMgr::GetGameObjs(LayerType layer)
	{		
		std::vector<GameObject*> gameObjs = activeScene->GetLayer(layer)->GetGameObjs();
		std::vector<GameObject*> ddolGameObjs = ddolScene->GetLayer(layer)->GetGameObjs();

		gameObjs.insert(gameObjs.end(), ddolGameObjs.begin(), ddolGameObjs.end());

		return gameObjs;
	}

	void SceneMgr::Initialize()
	{	
		ddolScene = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneMgr::Update()
	{
		activeScene->Update(); 
		ddolScene->Update(); 
	}

	void SceneMgr::LateUpdate()
	{
		activeScene->LateUpdate(); 
		ddolScene->LateUpdate();
	}

	void SceneMgr::Render(HDC _hdc)
	{
		activeScene->Render(_hdc); 
		ddolScene->Render(_hdc);
	}

	void SceneMgr::Destroy()
	{
		activeScene->Destroy(); 
		ddolScene->Destroy();
	}

	void SceneMgr::Release()
	{
		//static std::map<std::wstring, Scene*> scenes; 
		for (auto& iter : scenes)
		{
			if (iter.second == nullptr)
				continue; 

			delete iter.second; 
			iter.second = nullptr;
		}
	}
}