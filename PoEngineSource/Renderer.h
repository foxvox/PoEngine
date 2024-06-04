#pragma once 
#include "Camera.h" 
#include "Graphics.h" 
#include "GraphicDeviceDx11.h" 

namespace Bx
{
	extern Camera*				mainCam; 

	extern Vertex				vertices[3];
	extern ID3D11Buffer*		vertexBuffer;

	extern ID3DBlob*			vsBlob; 
	extern ID3D11VertexShader*  vsShader;

	extern ID3DBlob*			psBlob; 
	extern ID3D11PixelShader*	psShader; 

	extern ID3D11InputLayout*	inputLayouts;
}

