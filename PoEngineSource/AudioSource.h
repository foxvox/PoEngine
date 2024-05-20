#pragma once 
#include "Component.h" 
#include "AudioClip.h" 

namespace Bx
{
	class AudioSource : public Component 
	{
		AudioSource();
		~AudioSource();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Play();
		void Stop();
		void SetLoop(bool loop);

		void SetClip(AudioClip* _audioClip) { audioClip = _audioClip; }
		AudioClip* GetClip() { return audioClip; }

	private:
		AudioClip* audioClip;
	};
}


