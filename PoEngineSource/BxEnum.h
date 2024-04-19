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
