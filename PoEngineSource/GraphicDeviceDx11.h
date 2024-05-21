#pragma once 

#include <d3d11.h>
#include <d3dcompiler.h> 
#include "CommonInclude.h" 

#pragma comment(lib, "d3d11.lib") 
#pragma comment(lib, "d3dcompiler.lib") 

//https://github.com/kevinmoran/BeginnerDirect3D11

namespace Bx
{
	class GraphicDeviceDx11
	{
	public:
		GraphicDeviceDx11();
		~GraphicDeviceDx11(); 

		void Draw(); 

	private:
		Microsoft::WRL::ComPtr<ID3D11Device>			device; 
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>		context;
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			renderTarget;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	renderTargetView;
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			depthStencilBuffer; 
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	depthStencilView; 

		Microsoft::WRL::ComPtr<IDXGISwapChain>			swapChain;
		Microsoft::WRL::ComPtr<ID3D11SamplerState>		samplers;
	};
}


