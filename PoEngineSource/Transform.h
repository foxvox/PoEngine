#pragma once 
#include "Entity.h" 
#include "Component.h" 
#include "BxMath.h"

namespace Bx
{	 
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hdc) override;
		
		Vector2 GetPos() { return position; } 
		void	SetPos(Vector2 _pos) { position.x = _pos.x; position.y = _pos.y; }
		float	GetRot() { return rotation; } 
		void	SetRot(float _rot) { rotation = _rot; }
		Vector2 GetScale() { return scale; } 
		void	SetScale(Vector2 _scale) { scale = _scale; } 

	private: 
		Vector2 position; 
		Vector2 scale; 
		float	rotation; 
	};
}


