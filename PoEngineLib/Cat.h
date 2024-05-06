#pragma once
#include "GameObject.h" 

namespace Bx
{
	class Cat : public GameObject
	{
	public:
		Cat();
		virtual ~Cat();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

	private:		
	};

}
