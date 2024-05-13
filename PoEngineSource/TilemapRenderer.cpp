#include "TilemapRenderer.h"
#include "SpriteRenderer.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "Input.h" 
#include "BxTime.h" 
#include "Texture.h" 
#include "Camera.h" 
#include "Renderer.h" 

namespace Bx
{
	Vector2 TilemapRenderer::tileSpanV = Vector2::one;
	Vector2 TilemapRenderer::originTileSpan = Vector2::one;
	Vector2 TilemapRenderer::selectedIndex = Vector2::one;

	TilemapRenderer::TilemapRenderer()
		: Component(CompType::SR), texture(nullptr), multiple(3.f, 3.f), 
		index(0.f, 0.f), tileSpan(16.f, 16.f) 
	{
		tileSpanV = tileSpan * multiple; 
		originTileSpan = tileSpan;
	}

	TilemapRenderer::~TilemapRenderer()
	{}

	void TilemapRenderer::Initialize()
	{}

	void TilemapRenderer::Update()
	{
	}

	void TilemapRenderer::LateUpdate()
	{}

	void TilemapRenderer::Render(HDC _hdc)
	{
		if (texture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		float rot = tr->GetRot();
		Vector2 scale = tr->GetScale();

		Vector2 camPos = mainCam->CalPos(pos); 
		pos = camPos;

		if (texture->IsAlpha())
		{
			//���ĺ��带 ������ �ش� �̹����� ����ä���� �־�� �Ѵ�. 
			BLENDFUNCTION func{};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;  //0=>transparent, 255=>Opaque 				

			AlphaBlend(_hdc, 
				int(pos.x), int(pos.y),
				int(tileSpan.x * multiple.x * scale.x), int(tileSpan.y * multiple.y * scale.y),
				texture->GetHDC(),
				int(index.x * tileSpan.x), int(index.y * tileSpan.y),
				int((index.x + 1) * tileSpan.x), int((index.x + 1) * tileSpan.x),
				func);
		}
		else
		{
			//dest���� src���� ������ ����  
			TransparentBlt(_hdc, 
				int(pos.x), int(pos.y),
				int(tileSpan.x * multiple.x * scale.x), int(tileSpan.y * multiple.y * scale.y),
				texture->GetHDC(), 
				int(index.x * tileSpan.x), int(index.y * tileSpan.y), 
				int((index.x + 1) * tileSpan.x), int((index.x + 1) * tileSpan.x), 
				RGB(255, 0, 255));
		}
	}
}
