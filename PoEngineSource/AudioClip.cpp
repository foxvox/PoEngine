#include "AudioClip.h" 

namespace Bx
{
	AudioClip::AudioClip()
		: Resource(ResrcType::AUDIOCLIP), sound(nullptr), channel(nullptr), 
		minDistance(1.f), maxDistance(1000.f), isLoop(false) 
	{}
	
	AudioClip::~AudioClip()
	{
		sound->release();
		sound = nullptr;
	}
	
	HRESULT AudioClip::Load(const std::wstring& path)
	{
		//wsting => string 
		std::string cPath(path.begin(), path.end());
		if (!BxFMod::CreateSound(cPath, &sound))
			return S_FALSE;

		sound->set3DMinMaxDistance(minDistance, maxDistance);

		return S_OK;
	}

	void AudioClip::Play()
	{
		if (isLoop)
			sound->setMode(FMOD_LOOP_NORMAL);
		else
			sound->setMode(FMOD_LOOP_OFF);

		BxFMod::SoundPlay(sound, &channel);
	}

	void AudioClip::Stop()
	{
		channel->stop();
	}

	void AudioClip::Set3DAttributes(const Vector2 pos)
	{
		FMOD_VECTOR fmodPos(0.f, 0.f, 0.f);
		FMOD_VECTOR fmodVel(0.f, 0.f, 0.f);

		channel->set3DAttributes(&fmodPos, &fmodVel);
	}
}
