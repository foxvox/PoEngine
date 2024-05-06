#include "DontDestroyOnLoad.h"

Bx::DontDestroyOnLoad::DontDestroyOnLoad()
	: player(nullptr), cat(nullptr)
{}

Bx::DontDestroyOnLoad::~DontDestroyOnLoad()
{}

void Bx::DontDestroyOnLoad::Initialize()
{
	Scene::Initialize(); 
}

void Bx::DontDestroyOnLoad::Update()
{
	Scene::Update(); 
}

void Bx::DontDestroyOnLoad::LateUpdate()
{
	Scene::LateUpdate(); 
}

void Bx::DontDestroyOnLoad::Render(HDC _hdc)
{
	Scene::Render(_hdc); 
}

void Bx::DontDestroyOnLoad::OnEnter()
{
	Scene::OnEnter(); 
}

void Bx::DontDestroyOnLoad::OnExit()
{
	Scene::OnExit(); 
}
