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

		swapChain; 
		DXGI_SWAP_CHAIN_DESC swapChainDesc{}; 
		swapChainDesc.OutputWindow = app.GetHWND();
		//â���� �������� ����
		swapChainDesc.Windowed = true; 
		swapChainDesc.BufferCount = 2; 
		//Resize ������ �����ϰ� ���ش�. 
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; 
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
		//âũ�� ���� 
		swapChainDesc.BufferDesc.Width = app.GetWidth(); 
		swapChainDesc.BufferDesc.Height = app.GetHeight(); 
		//�ȼ��� ������ ũ�� ���� 
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 
		//�ִ� fps 
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 144; 
		//denominator �и� 
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1; 
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED; 
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; 

		//4X MSAA supported check
		UINT quality = 0; 
		device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quality); 

		Microsoft::WRL::ComPtr<IDXGIDevice>		dxgidevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter>	adapter = nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory>	factory = nullptr; 

		if (FAILED(device->QueryInterface(__uuidof(IDXGIDevice), (void**)dxgidevice.GetAddressOf())))  
			return; 

		if (FAILED(dxgidevice->GetParent(__uuidof(IDXGIAdapter), (void**)adapter.GetAddressOf())))
			return; 

		if (FAILED(adapter->GetParent(__uuidof(IDXGIAdapter), (void**)factory.GetAddressOf()))) 
			return; 

		if (FAILED(factory->CreateSwapChain(device.Get(), &swapChainDesc, swapChain.GetAddressOf())))
			return; 

	}

	void GraphicDeviceDx11::Draw()
	{

	}
}
