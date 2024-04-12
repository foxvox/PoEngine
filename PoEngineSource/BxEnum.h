#pragma once 

namespace Bx
{
	enum class CompType
	{
		CAMERA, 
		SCRIPT, 
		TRANS, 
		SR,		
		END, 
	};

	enum class LayerType
	{
		None, 
		BG,		
		PLAYER, 
		MAP, 
		MAX = 10, 
	};

	enum class ResrcType
	{
		Texture,
		AudioClip,
		Prefab, 
		End, 
	};
}
