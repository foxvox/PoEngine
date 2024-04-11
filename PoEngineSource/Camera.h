#pragma once 
#include "GameObject.h" 

namespace Bx
{
	class Camera : public Component 
	{
	public: 
		Vector2 CalPos(Vector2 _pos) const { return _pos - relativePos; }  

		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override; 

	private:		
		//std::vector<GameObject*> gameObjects; 
		Vector2		relativePos; 
		Vector2		resolution; 
		Vector2		destPos;
		GameObject* target; 
	};
}

