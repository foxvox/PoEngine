#pragma once 

namespace Bx
{
	enum class CompType
	{
		CAMERA, 
		SCRIPT, 
		TRANS, 
		SR,
		ANI, 
		END, 
	};

	enum class LayerType
	{
		NONE, 
		BG,		
		PLAYER, 
		MAP, 
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
