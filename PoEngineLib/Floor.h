#pragma once
#include "GameObject.h"

namespace Bx
{

	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

	private:

	};
}