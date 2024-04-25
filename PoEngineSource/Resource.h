#pragma once 
#include "Entity.h" 

namespace Bx
{
	class Resource abstract : public Entity  //�߻�Ŭ���� <== ��� �޾Ƽ� ����ؾ� �� 
	{
	public: 
		Resource(ResrcType _rcType);
		virtual ~Resource(); 

		virtual HRESULT Load(const std::wstring& _path) = 0;  //���������Լ� �ν��Ͻ��� ���� �� ����.  
		const std::wstring& GetPath() const { return path; } 
		void SetPath(const std::wstring& _path) { path = _path; } 

	private:
		ResrcType		rcType; 
		std::wstring	path;
	};

	//class Texture : public Resource;
	//class AudioClip : public Resource; 
}


