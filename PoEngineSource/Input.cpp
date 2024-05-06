#include "Input.h" 
#include "App.h" 
#include "BxMath.h" 

extern Bx::App app;  // �ܺ� ���Ͽ� �ִ� ���������� ����ϰڴٰ� ���漱��

namespace Bx
{	
	vector<Input::Key> Input::keys{};
	Vector2 Input::mousePos = Vector2::zero; 

	Input::Input() {}	
	Input::~Input() {}

	int ASCII[(size_t)KeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, 
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,  
	};

	void Input::Initialize()
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

	void Input::UpdateKey(Input::Key& _key)
	{
		//���� ������ �̿��� �����찡 ���� ��� Űó���� ��ȿȭ��Ų��. 
		if (GetFocus())
		{
			if (IsKeyDown(_key.keyCode))
			{
				UpdateKeyDown(_key);
			}
			else
			{
				UpdateKeyUp(_key);
			}

			SetFocusWndPos(); 
		} 
		else
		{
			ClearKeys(); 
		}
	}

	void Input::UpdateKeys()
	{
		/*
		lambda�� ���� ǥ���� �Ǵ� ���� �Լ�, �͸� �Լ�(anonymous function)�� �Ҹ��ϴ�.
		�� ������ �Լ� ��ü(functor)�� �����մϴ�. 
		�� �̸�ó�� ������ ������ �̸��� ���� �Լ��Դϴ�.
		[captures] (parameters) -> return type{ body } 
		lambda�� ������ ũ�� ĸó(capture), ����(parameter), 
		��ȯ��(return type), ����(body)�� �̷���� �ֽ��ϴ�.
		*/
		for_each(keys.begin(), keys.end(), 
			[](Key& key) -> void 
			{ 
				UpdateKey(key); 
			});
	}

	void Input::UpdateKeyDown(Input::Key& _key)
	{
		if (_key.isPressed == true)
			_key.keyState = KeyState::Pressed;
		else
			_key.keyState = KeyState::Down; 

		_key.isPressed = true; 
	}

	void Input::UpdateKeyUp(Input::Key& _key)
	{
		if (_key.isPressed == true)
			_key.keyState = KeyState::Up;
		else
			_key.keyState = KeyState::None;

		_key.isPressed = false;
	}

	void Input::ClearKeys()
	{
		for (Key& key : keys)
		{
			if (key.keyState == KeyState::Down || key.keyState == KeyState::Pressed)
			{
				key.keyState = KeyState::Up;
			}
			else if (key.keyState == KeyState::Up)
			{
				key.keyState = KeyState::None;
			}
			key.isPressed = false;
		}
	}

	bool Input::IsKeyDown(KeyCode _keyCode)
	{
		return GetAsyncKeyState(ASCII[(size_t)_keyCode]) & 0x8000;
	}

	void Input::SetFocusWndPos()
	{
		POINT mousePoint{};
		GetCursorPos(&mousePoint);
		ScreenToClient(app.GetHWND(), &mousePoint);

		mousePos.x = float(mousePoint.x);
		mousePos.y = float(mousePoint.y);
	}
}
