#pragma once 
#include "Resources.h" 
#include "Texture.h" 

namespace Bx
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"Cat", L"../Resources/alpha_cat.bmp");
		//Resources::Load<Texture>(L"Bubble", L"../Resources/bubble.png");
		//Resources::Load<Texture>(L"Effect", L"../Resources/effect.png");
		Resources::Load<Texture>(L"Player", L"../Resources/player.bmp");

	}
}

