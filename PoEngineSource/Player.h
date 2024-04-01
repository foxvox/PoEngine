#pragma once
#include "../PoEngineSource/GameObject.h" 

namespace Po
{
	class Player : public GameObject
	{
	public: 
		Player();
		~Player(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

	private:
	};

}

