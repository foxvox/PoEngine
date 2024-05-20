#pragma once 
#include "BxFMod.h" 
#include "Resource.h" 

namespace Bx
{
	class AudioClip : public Resource 
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		virtual HRESULT Load(const std::wstring& path) override; 
		void Play();
		void Stop();
		void Set3DAttributes(const Vector2 pos);
		void SetLoop(bool _isLoop) { isLoop = _isLoop; }

	private:
		FMOD::Sound* sound; 
		FMOD::Channel* channel; 
		float minDistance;
		float maxDistance;
		bool  isLoop;
	};

}


