#pragma once
#include "Scene.h" 

namespace Bx
{
	class Player;
	class Cat; 

	class PlayScene : public Scene 
	{
	public: 
		PlayScene();
		virtual ~PlayScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override; 
	private:
		Player*	player; 
		Cat*	cat; 
	};
}


