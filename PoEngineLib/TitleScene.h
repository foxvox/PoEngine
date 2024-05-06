#pragma once 
#include "Scene.h" 

namespace Bx 
{
	class TitleScene : public Scene 
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
	};
}



