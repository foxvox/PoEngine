#pragma once 
#include "Scene.h" 

namespace Po 
{
	class TitleScene : public Scene 
	{
	public:
		TitleScene();
		~TitleScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
	};
}



