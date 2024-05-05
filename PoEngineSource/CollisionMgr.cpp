#include "CollisionMgr.h" 
#include "Scene.h" 
#include "SceneMgr.h" 
#include "GameObject.h" 
#include "Collider.h" 

namespace Bx
{
	std::bitset<(UINT)LayerType::MAX> CollisionMgr::cm[(UINT)LayerType::MAX]{};

	void CollisionMgr::Init()
	{
	}

	void CollisionMgr::Update()
	{
		Scene* scene = SceneMgr::GetActiveScene(); 

		for (UINT row = 0; row < (UINT)LayerType::MAX; row++)
		{
			for (UINT col = 0; col < (UINT)LayerType::MAX; col++)
			{
				if (cm[row][col] == true)
				{
					LayerCollision(scene, (LayerType)row, (LayerType)col); 
				}
			}
		}
	}

	void CollisionMgr::LateUpdate()
	{
	}

	void CollisionMgr::Render(HDC _hdc)
	{
	}
	void CollisionMgr::LayerCollisionCheck(LayerType lhs, LayerType rhs, bool enable)
	{
		int row = 0;
		int col = 0; 

		if (lhs <= rhs)
		{
			row = (UINT)lhs; 
			col = (UINT)rhs; 
		}
		else
		{
			row = (UINT)rhs;
			col = (UINT)lhs; 
		}

		cm[row][col] = enable;
	}

	void CollisionMgr::LayerCollision(Scene* scene, LayerType lhs, LayerType rhs) 
	{
		const std::vector<GameObject*>& lObjs = scene->GetLayer(lhs)->GetGameObjects(); 
		const std::vector<GameObject*>& rObjs = scene->GetLayer(rhs)->GetGameObjects(); 

		for (GameObject* lObj : lObjs) 
		{
			if (lObj->IsActive() == false)
				continue; 
			Collider* lColl = lObj->GetComponent<Collider>();
			if (lColl == nullptr)
				continue; 

			for (GameObject* rObj : rObjs)
			{
				if (lObj->IsActive() == false)
					continue;
				Collider* rColl = rObj->GetComponent<Collider>();
				if (rColl == nullptr)
					continue;
				if (lObj == rObj)
					continue; 

				ColliderCollision(lColl, rColl); 
			}
		}
	}

	void CollisionMgr::ColliderCollision(Collider* lColl, Collider* rColl)
	{

	}
}
