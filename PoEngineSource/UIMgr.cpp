#include "UIMgr.h" 

namespace Bx
{
	std::unordered_map<UIType, UIBase*> UIMgr::uis{};
	std::stack<UIBase*> UIMgr::uiBases{};
	std::queue<UIType> UIMgr::reqUIQueues{};
	UIBase* UIMgr::activeUI = nullptr;

	void UIMgr::Initialize()
	{}

	void UIMgr::Update()
	{
		std::stack<UIBase*> uibs = uiBases;
		//스택이 비어있지 않다면...
		while (!uiBases.empty())
		{
			UIBase* uib = uibs.top();
			if (uib)
			{
				uib->Update(); 
				uibs.pop(); 
			}
		}

		//새로운 ui를 그려달라고 호출한 경우 
		if (reqUIQueues.size() > 0)
		{
			UIType reqUI = reqUIQueues.front(); 
			reqUIQueues.pop(); 
			OnLoad(reqUI);
		}
	}

	void UIMgr::LateUpdate()
	{
		std::stack<UIBase*> uibs = uiBases;
		//스택이 비어있지 않다면...
		while (!uiBases.empty())
		{
			UIBase* uib = uibs.top();
			if (uib)
			{
				uib->LateUpdate(); 
				uibs.pop();
			}
		}
	}

	void UIMgr::Render(HDC _hdc)
	{
		std::stack<UIBase*> uibs = uiBases;
		//스택이 비어있지 않다면...
		while (!uiBases.empty())
		{
			UIBase* uib = uibs.top();
			if (uib)
			{
				uib->Render(_hdc); 
				uibs.pop();
			}
		}
	}

	void UIMgr::OnLoad(UIType _type)
	{
		std::unordered_map<UIType, UIBase*>::iterator iter = uis.find(_type);

		if (iter == uis.end())
		{
			OnFail(); 
			return; 
		}

		OnComplete(iter->second); 
	}

	void UIMgr::OnComplete(UIBase* _addUI)
	{
		if (_addUI == nullptr)
			return; 

		_addUI->Initialize(); 
		_addUI->Active();
		_addUI->Update();

		/*만약에 현재 추가된 ui가 전체화면이라면 전체화면 ui 외 나머지는 전부 비활성화*/ 		
		if (_addUI->IsFullScreen())
		{
			std::stack<UIBase*> uibs = uiBases;
			//스택이 비어있지 않다면...
			while (!uiBases.empty())
			{
				UIBase* uib = uibs.top();
				if (uib)
				{
					uib->Inactive(); 
					uibs.pop();
				}
			}
		}

		uiBases.push(_addUI); 
		activeUI = nullptr; 
	}

	void UIMgr::OnFail()
	{
		activeUI = nullptr;
	}

	void UIMgr::Push(UIType _type)
	{
		reqUIQueues.push(_type); 
	}

	void UIMgr::Pop(UIType _type)
	{
		if (uiBases.size() <= 0)
			return; 

		UIBase* uib = nullptr; 
		while (uiBases.size() > 0)
		{
			uib = uiBases.top(); 
		}
	}
}

