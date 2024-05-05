#pragma once
#include "CommonInclude.h" 
#include "Collider.h" 

namespace Bx
{
	class CollisionMgr
	{
	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc);
		static void LayerCollisionCheck(LayerType lhs, LayerType rhs, bool enable); 
		static void LayerCollision(class Scene* scene, LayerType lhs, LayerType rhs);
		static void ColliderCollision(Collider* lColl, Collider* rColl);

	private:
		//ltcm layertype collision matrix
		static std::bitset<(UINT)LayerType::MAX> cm[(UINT)LayerType::MAX]; 
	};
}


