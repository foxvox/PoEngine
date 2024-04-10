#include "Input.h" 

namespace Bx
{	
	vector<Input::Key> Input::keys{};

	Input::Input() {}
	
	Input::~Input() {}

	int ASCII[(size_t)KeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, 
	};

	void Input::Init()
	{		
		Input::CreateKeys();	
	}

	void Input::Update()
	{
		UpdateKeys(); 
	}

	void Input::CreateKeys()
	{		
		for (size_t i = 0; i < (size_t)KeyCode::END; i++)
		{
			Key key{};
			key.isPressed = false;
			key.keyState = KeyState::None;
			key.keyCode = (KeyCode)i;

			keys.push_back(key);
		}
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if (IsKeyDown(key.keyCode))
		{
			UpdateKeyDown(key);
		}
		else
		{
			UpdateKeyUp(key); 
		}
	}

	void Input::UpdateKeys()
	{
		/*
		lambda는 람다 표현식 또는 람다 함수, 익명 함수(anonymous function)로 불립니다.
		그 성질은 함수 객체(functor)와 동일합니다. 
		그 이름처럼 몸통은 있지만 이름이 없는 함수입니다.
		[captures] (parameters) -> return type{ body } 
		lambda의 문법은 크게 캡처(capture), 인자(parameter), 
		반환형(return type), 몸통(body)로 이루어져 있습니다.
		*/
		for_each(keys.begin(), keys.end(), 
			[](Key& key) -> void 
			{ 
				UpdateKey(key); 
			});
	}

	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.isPressed == true)
			key.keyState = KeyState::Pressed;
		else
			key.keyState = KeyState::Down; 

		key.isPressed = true; 
	}

	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.isPressed == true)
			key.keyState = KeyState::Up;
		else
			key.keyState = KeyState::None;

		key.isPressed = false;
	}

	bool Input::IsKeyDown(KeyCode _keyCode)
	{
		return GetAsyncKeyState(ASCII[(size_t)_keyCode]) & 0x8000;
	}

}
