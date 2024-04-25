#pragma once 
#include "Entity.h" 

namespace Bx
{
	class Resource abstract : public Entity  //추상클래스 <== 상속 받아서 사용해야 함 
	{
	public: 
		Resource(ResrcType _rcType);
		virtual ~Resource(); 

		virtual HRESULT Load(const std::wstring& _path) = 0;  //순수가상함수 인스턴스를 만들 수 없다.  
		const std::wstring& GetPath() const { return path; } 
		void SetPath(const std::wstring& _path) { path = _path; } 

	private:
		ResrcType		rcType; 
		std::wstring	path;
	};

	//class Texture : public Resource;
	//class AudioClip : public Resource; 
}


