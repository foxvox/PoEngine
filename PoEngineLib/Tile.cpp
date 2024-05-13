#include "Tile.h" 
#include "Transform.h"
#include "TilemapRenderer.h" 

namespace Bx
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Tile::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Tile::SetIndexPos(int _x, int _y)
	{
		Transform* tr = GetComponent<Transform>(); 
		Vector2 pos; 
		pos.x = _x * TilemapRenderer::tileSpanV.x;
		pos.y = _y * TilemapRenderer::tileSpanV.y; 
		tr->SetPos(pos);
	}
}
