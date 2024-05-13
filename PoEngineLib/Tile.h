#pragma once
#include "GameObject.h" 

namespace Bx
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void SetIndexPos(int _x, int _y); 

	private:
	};
}

