#pragma once
#include "CommonInclude.h" 

namespace Bx
{
	class Entity 
	{
	public:
		Entity();
		virtual ~Entity(); 

		void SetName(const std::wstring& _name) { name = _name; }
		std::wstring& GetName() { return name; } 

	private:
		std::wstring name; 
	};
}



