#pragma once
#include "CommonInclude.h" 
#include "Collider.h" 

namespace Bx
{
	union CollisionID
	{
		struct
		{
			UINT32 left; 
			UINT32 right; 
		};

		UINT64 id; 
	};

	class CollisionMgr
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc);
		static void Clear(); 

		static void LayerCollisionCheck(LayerType lhs, LayerType rhs, bool enable); 
		static void LayerCollision(class Scene* scene, LayerType lhs, LayerType rhs);
		static void ColliderCollision(Collider* lColl, Collider* rColl);
		static bool Intersect(Collider* lColl, Collider* rColl);

	private:		
		static std::bitset<(UINT)LayerType::MAX> collMat[(UINT)LayerType::MAX]; 
		static std::unordered_map<UINT64, bool> collMap; 
	};
}


