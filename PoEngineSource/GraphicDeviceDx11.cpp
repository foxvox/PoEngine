#include "GraphicDeviceDx11.h" 
#include "App.h" 

extern Bx::App app; 

namespace Bx
{
	GraphicDeviceDx11::GraphicDeviceDx11()
	{}
	
	GraphicDeviceDx11::~GraphicDeviceDx11()
	{}

	void GraphicDeviceDx11::Initialize()
	{
		D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 }; 
		UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT; 
#if defined(DEBUG) || defined(_DEBUG) 
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG; 
#endif 

		HRESULT hr = D3D11CreateDevice(0, D3D_DRIVER_TYPE_HARDWARE, 0, creationFlags, featureLevels, ARRAYSIZE(featureLevels), 
			D3D11_SDK_VERSION, device.GetAddressOf(), 0, context.GetAddressOf()); 

		DXGI_SWAP_CHAIN_DESC swapChainDesc{}; 
		swapChainDesc.OutputWindow = app.GetHWND();
		//창모드로 실행할지 선택
		swapChainDesc.Windowed = true; 
		swapChainDesc.BufferCount = 2; 
		//Resize 실행을 가능하게 해준다. 
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; 
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
		//창크기 지정 
		swapChainDesc.BufferDesc.Width = app.GetWidth(); 
		swapChainDesc.BufferDesc.Height = app.GetHeight(); 
		//픽셀의 데이터 크기 지정 
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 
		//최대 fps 
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 144; 
		//denominator 분모 
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1; 
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED; 
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; 

		//4X MSAA supported check
		UINT quality = 0; 
		device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quality); 

		/*if (quality > 0)
		{
			swapChainDesc.SampleDesc.Count = 4; 
			swapChainDesc.SampleDesc.Quality = quality - 1; 
		}
		else
		{
			swapChainDesc.SampleDesc.Count = 1;
			swapChainDesc.SampleDesc.Quality = 0;
		}*/ 

		//임시로 else part 사용 
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		Microsoft::WRL::ComPtr<IDXGIDevice>		dxgiDevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter>	adapter = nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory>	factory = nullptr; 

		if (FAILED(device->QueryInterface(__uuidof(IDXGIDevice), (void**)dxgiDevice.GetAddressOf())))  
			return; 

		if (FAILED(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)adapter.GetAddressOf())))
			return; 

		if (FAILED(adapter->GetParent(__uuidof(IDXGIFactory), (void**)factory.GetAddressOf()))) 
			return; 

		if (FAILED(factory->CreateSwapChain(device.Get(), &swapChainDesc, swapChain.GetAddressOf())))
			return;

		swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)renderTarget.GetAddressOf()); 
		device->CreateRenderTargetView(renderTarget.Get(), nullptr, renderTargetView.GetAddressOf()); 

		D3D11_TEXTURE2D_DESC depthStencilDesc{}; 
		depthStencilDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL; 
		depthStencilDesc.Format = DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		depthStencilDesc.Width = app.GetWidth(); 
		depthStencilDesc.Height = app.GetHeight(); 
		depthStencilDesc.ArraySize = 1; 
		depthStencilDesc.SampleDesc.Count = 1; 
		depthStencilDesc.SampleDesc.Quality = 0; 


		device->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf());
	}

	void GraphicDeviceDx11::Draw()
	{

	}
}
