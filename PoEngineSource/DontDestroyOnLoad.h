#pragma once
#include "Scene.h" 

namespace Bx
{
	class Player;
	class Cat;

	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override;
	private:
		Player* player;
		Cat* cat;
	};
}

