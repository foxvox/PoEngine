#pragma once
#include "../PoEngineSource/Scene.h" 

namespace Po
{
	class PlayScene : public Scene 
	{
	public: 
		PlayScene();
		~PlayScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
	private:
	};
}


