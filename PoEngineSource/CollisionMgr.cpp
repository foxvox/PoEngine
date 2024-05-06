#include "CollisionMgr.h" 
#include "Scene.h" 
#include "SceneMgr.h" 
#include "GameObject.h" 
#include "Transform.h" 
#include "BoxCollider2D.h"
#include "CircleCollider2D.h" 
#include "BxMath.h" 

namespace Bx
{
	std::bitset<(UINT)LayerType::MAX> CollisionMgr::collMat[(UINT)LayerType::MAX]{};
	std::unordered_map<UINT64, bool> CollisionMgr::collMap{};

	void CollisionMgr::Initialize()
	{}

	void CollisionMgr::Update()
	{
		Scene* scene = SceneMgr::GetActiveScene(); 

		for (UINT row = 0; row < (UINT)LayerType::MAX; row++)
		{
			for (UINT col = 0; col < (UINT)LayerType::MAX; col++)
			{
				if (collMat[row][col] == true)
				{
					LayerCollision(scene, (LayerType)row, (LayerType)col); 
				}
			}
		}
	}

	void CollisionMgr::LateUpdate()
	{}

	void CollisionMgr::Render(HDC _hdc)
	{}

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

		collMat[row][col] = enable;
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
		CollisionID _id{}; 
		_id.left = lColl->GetCID(); 
		_id.right = rColl->GetCID(); 

		auto iter = collMap.find(_id.id); 
		if (iter == collMap.end())
		{
			collMap.insert(std::make_pair(_id.id, false)); 
			iter = collMap.find(_id.id); 
		}

		//충돌체크를 해준다.
		if (Intersect(lColl, rColl))
		{
			//충돌 상태인데 아직 충돌상태 정보를 갖고 있지 않은 경우 
			if (iter->second == false)
			{
				lColl->OnCollisionEnter(rColl); 
				rColl->OnCollisionEnter(lColl); 
				iter->second = true; 
			} 
			//충돌 상태이고 충돌 상태 정보를 갖고 있는 경우 
			else
			{
				lColl->OnCollisionStay(rColl);
				rColl->OnCollisionStay(lColl);
			}
		}
		else
		{
			//충돌 상태가 아닌데 아직 충돌상태 정보를 갖고 있는 경우 
			if (iter->second == true)
			{
				lColl->OnCollisionExit(rColl);
				rColl->OnCollisionExit(lColl);
				iter->second = false; 
			}
		}
	}

	bool CollisionMgr::Intersect(Collider* lColl, Collider* rColl)
	{		
		Transform* lTr = lColl->GetOwner()->GetComponent<Transform>();
		Transform* rTr = rColl->GetOwner()->GetComponent<Transform>();

		//Vector 연산자 오버로딩 call by value 형태여야 이름없는 Vector 처리가 된다. 
		Vector2 lPos = lTr->GetPos() + lColl->GetOffset();
		Vector2 rPos = rTr->GetPos() + rColl->GetOffset();

		// span 1,1 일떄 기본크기가 100픽셀
		Vector2 lSpan = lColl->GetSpan() * 100.f;
		Vector2 rSpan = rColl->GetSpan() * 100.f;

		ColliderType lType = lColl->GetColliderType();
		ColliderType rType = rColl->GetColliderType();

		//rect-rect 충돌 
		if (lType == ColliderType::RECT2D && rType == ColliderType::RECT2D)
		{
			if (fabs(lPos.x - rPos.x) < fabs(lSpan.x / 2.f + rSpan.x / 2.f)
				&& fabs(lPos.y - rPos.y) < fabs(lSpan.y / 2.f + rSpan.y / 2.f))
			{
				return true;
			}
		}

		//circle-circle 충돌
		if (lType == ColliderType::CIRCLE2D && rType == ColliderType::CIRCLE2D)
		{			
			Vector2 lCirclePos = lPos + (lSpan / 2.f);
			Vector2 rCirclePos = rPos + (rSpan / 2.f);
			float distance = (lCirclePos - rCirclePos).Length();
			if (distance <= (lSpan.x / 2.f + rSpan.x / 2.f))
			{
				return true;
			}
		}

		if ((lType == ColliderType::CIRCLE2D && rType == ColliderType::RECT2D)
			|| (lType == ColliderType::RECT2D && rType == ColliderType::CIRCLE2D))
		{}		

		return false;
	}
}
