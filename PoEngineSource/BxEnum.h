#pragma once 

namespace Bx
{
	enum class CompType
	{		 
		TRANS, 
		COLLIDER, 
		RIGIDBODY, 
		SCRIPT,
		SR,
		ANIMATOR,
		CAMERA,	
		AUDIOLISTENER, 
		AUDIOSRC, 
		END, 
	};

	enum class LayerType
	{
		NONE, 
		BG,	
		TILE,
		ANIMAL, 
		PLAYER,
		FLOOR,  
		PARTICLE, 
		MAX = 16, 
	};

	enum class ResrcType 
	{
		TEXTURE,
		MESH, 
		AUDIOCLIP,
		ANI, 
		SHADER, 
		PREFAB, 
		END, 
	};

	enum class ColliderType
	{
		CIRCLE2D,
		RECT2D,
		END,
	};

	enum class UIType
	{
		HPBAR,
		BUTTON,
		END,
	};
}



