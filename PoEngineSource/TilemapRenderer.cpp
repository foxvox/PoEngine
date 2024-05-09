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
		//ķ��ġ�� ���ӿ�����Ʈ ��ġ�� �Ҵ�
		//pos = camPos; 

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
				int(tileSpan.x * span.x * scale.x), int(tileSpan.y * span.y * scale.y),
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
				int(tileSpan.x * span.x * scale.x), int(tileSpan.y * span.y * scale.y),
				texture->GetHDC(), 
				int(index.x * tileSpan.x), int(index.y * tileSpan.y), 
				int((index.x + 1) * tileSpan.x), int((index.x + 1) * tileSpan.x), 
				RGB(255, 0, 255));
		}
	}
}
