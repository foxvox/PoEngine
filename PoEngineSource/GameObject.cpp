#include "GameObject.h" 
#include "Time.h" 

namespace Po
{
	GameObject::GameObject()
		: x(0.0f), y(0.0f)
	{}	

	GameObject::~GameObject() 
	{
		for (Component* comp : components)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Init()
	{
		for (Component* comp : components)
		{
			comp->Init(); 
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : components)
		{
			comp->Update(); 
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : components)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC _hdc)
	{
		for (Component* comp : components)
		{
			comp->Render(_hdc);
		}		
	}
}
