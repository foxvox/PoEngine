#pragma once 

namespace Bx
{
	enum class CompType
	{
		SCRIPT, 
		TRANS, 
		SR, 
		END,
	};

	enum class LayerType
	{
		//None, 
		BG,		
		Player,  
		Max = 10, 
	};

	enum class ResrcType
	{
		Texture,
		AudioClip,
		Prefab, 
		End, 
	};
}
