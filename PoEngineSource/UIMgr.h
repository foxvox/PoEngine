#pragma once 
#include "CommonInclude.h" 
#include "UIBase.h" 

namespace Bx
{
	class UIMgr 
	{
	public:
		static void Initialize(); 
		static void Update(); 
		static void LateUpdate(); 
		static void Render(HDC _hdc); 

		static void OnLoad(UIType _type); 
		static void OnComplete(UIBase* _addUI); 
		static void OnFail(); 

		static void Push(UIType _type); 
		static void Pop(UIType _type); 

	private:
		static std::unordered_map<UIType, UIBase*> uis; 
		static std::stack<UIBase*> uiBases; 
		static std::queue<UIType> reqUIQueues;
		static UIBase* activeUI; 

	};
}



