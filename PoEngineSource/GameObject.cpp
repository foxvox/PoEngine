#include "GameObject.h" 
#include "BxTime.h" 
#include "Transform.h" 

namespace Bx
{
	GameObject::GameObject()		
	{
		components.resize((size_t)CompType::END); 
		InitTransform(); 
	}	

	GameObject::~GameObject() 
	{
		for (Component* comp : components)
		{
			if (comp == nullptr)
				continue; 

			delete comp;
			comp = nullptr;
		}
	} 

	void GameObject::InitTransform()
	{
		AddComponent<Transform>();
	}

	void GameObject::Init()
	{
		for (Component* comp : components)
		{
			if (comp == nullptr)
				continue; 

			comp->Init(); 
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : components)
		{
			if (comp == nullptr)
				continue;

			comp->Update(); 
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : components)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC _hdc)
	{
		for (Component* comp : components)
		{
			if (comp == nullptr)
				continue;

			comp->Render(_hdc);
		}		
	}

}
