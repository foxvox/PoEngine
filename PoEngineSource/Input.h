#pragma once 
#include "CommonInclude.h" 

using namespace std; 

namespace Po
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

		static void Init();
		static void Update(); 

		static bool GetKeyDown(KeyCode _keyCode)
		{
			return keys[(UINT)_keyCode].keyState == KeyState::Down; 
		}

		static bool GetKeyUp(KeyCode _keyCode)
		{
			return keys[(UINT)_keyCode].keyState == KeyState::Up; 
		}

		static bool GetKey(KeyCode _keyCode)
		{
			return keys[(UINT)_keyCode].keyState == KeyState::Pressed;
		}

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(KeyCode _keyCode);
		static void UpdateKeyDown(Input::Key& key); 
		static void UpdateKeyUp(Input::Key& key);

	private:		
		static vector<Key> keys; 
	};
}


