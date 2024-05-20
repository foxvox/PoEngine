#include "AudioSource.h" 
#include "Transform.h" 
#include "GameObject.h" 
#include "BxFMod.h" 

namespace Bx
{
	AudioSource::AudioSource() 
		: Component(CompType::AUDIOSRC), audioClip(nullptr) 
	{}
	
	AudioSource::~AudioSource()
	{}
	
	void AudioSource::Initialize()
	{}
	
	void AudioSource::Update()
	{}
	
	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		audioClip->Set3DAttributes(pos); 
	}
	
	void AudioSource::Render(HDC hdc)
	{}
	
	void AudioSource::Play()
	{
		audioClip->Play(); 
	}
	
	void AudioSource::Stop()
	{
		audioClip->Stop(); 
	}

	void AudioSource::SetLoop(bool loop)
	{
		audioClip->SetLoop(loop); 
	}
}
