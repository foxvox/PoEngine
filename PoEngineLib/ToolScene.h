#pragma once
#include "Scene.h" 
#include "Tile.h" 

namespace Bx
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override;

		void Save(); 
		void Load(); 
	private:
		std::vector<Tile*> tiles;
	};
}

LRESULT CALLBACK TileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

