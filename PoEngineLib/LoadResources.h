#pragma once 
#include "Resources.h" 
#include "Texture.h" 

namespace Bx
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"Map", L"../Resources/img/map/map_pure.png"); 
		Resources::Load<Texture>(L"Pacman", L"../Resources/img/pacman/0.png");  
		//Resources::Load<Texture>(L"Chicken", L"../Resources/chicken.bmp"); 
		Resources::Load<Texture>(L"Cat", L"../Resources/alpha_cat.bmp");
	}
}

