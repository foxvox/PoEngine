#include "AudioListener.h"
#include "Transform.h" 
#include "GameObject.h" 
#include "BxFMod.h" 

Bx::AudioListener::AudioListener() 
	: Component(CompType::AUDIOLISTENER)
{}

Bx::AudioListener::~AudioListener()
{}

void Bx::AudioListener::Initialize()
{}

void Bx::AudioListener::Update() 
{}

void Bx::AudioListener::LateUpdate()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	BxFMod::Set3DListenerAttributes(&pos);
}

void Bx::AudioListener::Render(HDC hdc)
{}
