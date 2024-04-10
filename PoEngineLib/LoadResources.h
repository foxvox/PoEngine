#pragma once 
#include "Resources.h" 
#include "Texture.h" 

namespace Bx
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"BG", L"C:/DevCpp/img/girl.png");
	}
}

