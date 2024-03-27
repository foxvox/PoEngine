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
		Z, X, C, V, B, N, M, END, 
	};

	class Input
	{
	public: 
		Input();
		~Input();

		struct Key
		{
			KeyCode keyCode; 
			KeyState keyState; 
			bool isPressed; 
		}; 

		static void Init();
		static void Update(); 

		static bool GetKeyDown(KeyCode _keyCode);
		static bool GetKeyUp(KeyCode _keyCode); 
		static bool GetKey(KeyCode _keyCode); 

	private:		
		static vector<Key> keys; 
	};
}


