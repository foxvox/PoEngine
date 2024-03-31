#pragma once
#include "Component.h" 

namespace Po
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer(); 

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

	private:
	};
}



