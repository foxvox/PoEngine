#pragma once
#include "CommonInclude.h" 

namespace Bx
{
	class CollisionMgr
	{
	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hdc);
		static void LayerCollisionCheck(); 

	private:
		//ltcm layertype collision matrix
		std::bitset<(UINT)LayerType::MAX> ltcm[(UINT)LayerType::MAX]; 
	};
}


