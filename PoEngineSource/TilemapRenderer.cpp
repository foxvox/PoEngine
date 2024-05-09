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
	TilemapRenderer::TilemapRenderer()
		: Component(CompType::SR), texture(nullptr), span(Vector2::one), 
		index(Vector2::zero), tileSpan(16.f, 16.f) 
	{}

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

		//Vector2 camPos = camera->CalPos(pos); 
		//캠위치를 게임오브젝트 위치에 할당
		//pos = camPos; 

		if (texture->IsAlpha())
		{
			//알파블렌드를 쓰려면 해당 이미지에 알파채널이 있어야 한다. 
			BLENDFUNCTION func{};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;  //0=>transparent, 255=>Opaque 				

			AlphaBlend(_hdc, 
				int(pos.x), int(pos.y),
				int(tileSpan.x * span.x * scale.x), int(tileSpan.y * span.y * scale.y),
				texture->GetHDC(),
				int(index.x * tileSpan.x), int(index.y * tileSpan.y),
				int((index.x + 1) * tileSpan.x), int((index.x + 1) * tileSpan.x),
				func);
		}
		else
		{
			//dest먼저 src나중 순서로 사용됨  
			TransparentBlt(_hdc, 
				int(pos.x), int(pos.y),
				int(tileSpan.x * span.x * scale.x), int(tileSpan.y * span.y * scale.y),
				texture->GetHDC(), 
				int(index.x * tileSpan.x), int(index.y * tileSpan.y), 
				int((index.x + 1) * tileSpan.x), int((index.x + 1) * tileSpan.x), 
				RGB(255, 0, 255));
		}
	}
}
