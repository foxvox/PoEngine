#include "GraphicDeviceDx11.h" 
#include "App.h" 
#include "Renderer.h" 

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
		swapChainDesc.Windowed	  = true; 
		swapChainDesc.BufferCount = 2; 
		//Resize 실행을 가능하게 해준다. 
		swapChainDesc.Flags		  = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; 
		swapChainDesc.SwapEffect  = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
		//창크기 지정 
		swapChainDesc.BufferDesc.Width  = app.GetWidth(); 
		swapChainDesc.BufferDesc.Height = app.GetHeight(); 
		//픽셀의 데이터 크기 지정 
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 
		//최대 fps 
		swapChainDesc.BufferDesc.RefreshRate.Numerator		= 144; 
		//denominator 분모 
		swapChainDesc.BufferDesc.RefreshRate.Denominator	= 1; 
		swapChainDesc.BufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED; 
		swapChainDesc.BufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; 

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
		swapChainDesc.SampleDesc.Count	 = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		Microsoft::WRL::ComPtr<IDXGIDevice>		dxgiDevice  = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter>	adapter		= nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory>	factory		= nullptr; 

		if (FAILED(device->QueryInterface(__uuidof(IDXGIDevice), (void**)dxgiDevice.GetAddressOf())))  
			return; 

		if (FAILED(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)adapter.GetAddressOf())))
			return; 

		if (FAILED(adapter->GetParent(__uuidof(IDXGIFactory), (void**)factory.GetAddressOf()))) 
			return; 

		if (FAILED(factory->CreateSwapChain(device.Get(), &swapChainDesc, swapChain.GetAddressOf())))
			return;

		//스왑체인에 있는 렌더타겟 가져와서 렌더타겟뷰 생성
		swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)renderTarget.GetAddressOf()); 
		device->CreateRenderTargetView(renderTarget.Get(), nullptr, renderTargetView.GetAddressOf()); 

		D3D11_TEXTURE2D_DESC depthStencilDesc{}; 
		depthStencilDesc.BindFlags			= D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL; 
		depthStencilDesc.Format				= DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Usage				= D3D11_USAGE::D3D11_USAGE_DEFAULT;
		depthStencilDesc.Width				= app.GetWidth(); 
		depthStencilDesc.Height				= app.GetHeight(); 
		depthStencilDesc.ArraySize			= 1; 
		depthStencilDesc.SampleDesc.Count	= 1; 
		depthStencilDesc.SampleDesc.Quality = 0; 

		//깊이버퍼, 깊이버퍼뷰 생성
		if (FAILED(device->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf()))) 
			return; 

		if (FAILED(device->CreateDepthStencilView(depthStencil.Get(), nullptr, depthStencilView.GetAddressOf())))
			return; 

		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS; 
		shaderFlags		 |= D3DCOMPILE_DEBUG; 
		shaderFlags		 |= D3DCOMPILE_SKIP_OPTIMIZATION; 

		//vertex shader 
		{
			ID3DBlob* errorBlob = nullptr;
			D3DCompileFromFile(L"../ShaderSrc/TriangleVS.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, 
				"main", "vs_5_0", shaderFlags, 0, &vsBlob, &errorBlob);

			device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vsShader); 
		}

		//pixel shader 
		{			
			ID3DBlob* errorBlob = nullptr; 
			D3DCompileFromFile(L"../ShaderSrc/TrianglePS.hlsl", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
				"main", "ps_5_0", shaderFlags, 0, &psBlob, &errorBlob); 

			device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &psShader); 
		}

		D3D11_INPUT_ELEMENT_DESC inputLayoutDesces[2] = {}; 

		inputLayoutDesces[0].AlignedByteOffset  = 0; 
		inputLayoutDesces[0].Format				= DXGI_FORMAT_R32G32B32_FLOAT; 
		inputLayoutDesces[0].InputSlot			= 0;
		inputLayoutDesces[0].InputSlotClass		= D3D11_INPUT_PER_VERTEX_DATA; 
		inputLayoutDesces[0].SemanticName		= "POSITION"; 
		inputLayoutDesces[0].SemanticIndex		= 0; 

		inputLayoutDesces[1].AlignedByteOffset	= 12;
		inputLayoutDesces[1].Format				= DXGI_FORMAT_R32G32B32A32_FLOAT;
		inputLayoutDesces[1].InputSlot			= 0;
		inputLayoutDesces[1].InputSlotClass		= D3D11_INPUT_PER_VERTEX_DATA;
		inputLayoutDesces[1].SemanticName		= "COLOR"; 
		inputLayoutDesces[1].SemanticIndex		= 0;

		device->CreateInputLayout(inputLayoutDesces, 1, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &inputLayouts); 

		D3D11_BUFFER_DESC bufferDesc{}; 

		bufferDesc.ByteWidth		= sizeof(Vertex) * 3; 
		bufferDesc.BindFlags		= D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER; 
		bufferDesc.Usage			= D3D11_USAGE::D3D11_USAGE_DYNAMIC; 
		bufferDesc.CPUAccessFlags	= D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE; 
	}

	void GraphicDeviceDx11::Draw()
	{
		//렌더타겟 초기화 
		FLOAT backgroundColor[4] = { 0.2f, 0.2f, 0.2f, 1.f }; 
		context->ClearRenderTargetView(renderTargetView.Get(), backgroundColor); 

		//스왑체인에게 그려달라고 함
		swapChain->Present(1, 0);  
	}
}
