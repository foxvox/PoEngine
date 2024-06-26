#include "Renderer.h" 

namespace Bx
{
	Camera*				mainCam = nullptr; 

	Vertex				vertices[3] = {};  
	ID3D11Buffer*		vertexBuffer = nullptr; 
	ID3DBlob*			vsBlob = nullptr;  
	ID3D11VertexShader* vsShader = nullptr; 
	ID3DBlob*			psBlob = nullptr; 
	ID3D11PixelShader*  psShader = nullptr; 
	ID3D11InputLayout*  inputLayouts = nullptr; 
}
