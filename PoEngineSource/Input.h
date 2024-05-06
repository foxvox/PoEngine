#pragma once 
#include "CommonInclude.h" 
#include "BxMath.h"

using namespace std; 

namespace Bx
{
	enum class KeyState
	{
		Down, Pressed, Up, None, 
	};

	enum class KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P, 
		A, S, D, F, G, H, J, K, L, 
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up, 
		LButton, MButton, RButton, 
		END,
	};

	class Input
	{
	public: 
		Input();
		~Input();

		struct Key
		{
			KeyCode		keyCode; 
			KeyState	keyState; 
			bool		isPressed; 
		}; 

		static void Initialize();
		static void Update(); 

		__forceinline static bool GetKeyDown(KeyCode _keyCode)
		{
			return keys[(size_t)_keyCode].keyState == KeyState::Down;
		}

		__forceinline static bool GetKeyUp(KeyCode _keyCode)
		{
			return keys[(size_t)_keyCode].keyState == KeyState::Up;
		}

		__forceinline static bool GetKey(KeyCode _keyCode)
		{
			return keys[(size_t)_keyCode].keyState == KeyState::Pressed; 
		}

		__forceinline static Vector2 GetMousePos() { return mousePos; } 

		static bool	IsKeyDown(KeyCode _keyCode);
		static void SetFocusWndPos(); 
		static void	CreateKeys();
		static void	UpdateKeys();
		static void	UpdateKey(Input::Key& _key);		
		static void	UpdateKeyDown(Input::Key& _key); 
		static void	UpdateKeyUp(Input::Key& _key);
		static void ClearKeys(); 

		static vector<Key> keys; 
		static Vector2   mousePos; 
	};
}


