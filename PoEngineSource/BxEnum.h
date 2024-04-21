#pragma once 

namespace Bx
{
	enum class CompType
	{		 
		TRANS, 
		SR,
		ANI, 
		SCRIPT,
		CAMERA,	
		END, 
	};

	enum class LayerType
	{
		NONE, 
		BG,	
		ANIMAL, 
		PLAYER, 
		PARTICLE, 
		MAX = 10, 
	};

	enum class ResrcType 
	{
		TEXTURE,
		AUDIOCLIP,
		ANI, 
		PREFAB, 
		END, 
	};
}
