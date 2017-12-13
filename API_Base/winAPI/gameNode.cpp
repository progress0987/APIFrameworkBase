#include "stdafx.h"
#include "gameNode.h"
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "winmm.lib")

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}
HRESULT gameNode::initD3D(HWND hWnd) {
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL) {			//����̽��� �����ϱ� ���� D3D ��ü ����
		return E_FAIL;
	}
	D3DDISPLAYMODE d3ddm;
	g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	g_pD3D->CreateDevice(					//��µ� ����̽��� �����ϴºκ�
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pd3dDevice
	);
	if (FAILED(g_pd3dDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &g_pd3dSurface))) {
		return E_FAIL;
	}
	//g_pd3dSurface->GetDC(&backDC);
	return S_OK;														//����̽� �������� ó�� �Ϸ�
}
HRESULT gameNode::init(void)
{
	hdc = GetDC(_hWnd);
	managerInit = false;
	return S_OK;
}
HRESULT gameNode::init(bool managerInit)
{
	this->managerInit = managerInit;
	/////////////////////////�׽�Ʈ��
	//g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//if (g_pD3D == NULL) {			//����̽��� �����ϱ� ���� D3D ��ü ����
	//	return E_FAIL;
	//}
	//D3DDISPLAYMODE d3ddm;
	//g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
	//D3DPRESENT_PARAMETERS d3dpp;
	//ZeroMemory(&d3dpp, sizeof(d3dpp));
	//d3dpp.Windowed = TRUE;
	//d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//d3dpp.BackBufferFormat = d3ddm.Format;
	//d3dpp.EnableAutoDepthStencil = TRUE;
	//d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	//g_pD3D->CreateDevice(					//��µ� ����̽��� �����ϴºκ�
	//	D3DADAPTER_DEFAULT,
	//	D3DDEVTYPE_HAL,
	//	_hWnd,
	//	D3DCREATE_HARDWARE_VERTEXPROCESSING,
	//	&d3dpp,
	//	&g_pd3dDevice
	//);
	////////////////////////////////////////////////////////

	initD3D(_hWnd);
	if (managerInit) {
		SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		INIDATAMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		TXTDATA->init();
	}
	return S_OK;
}
 void gameNode::release(void)
 {
	 if (managerInit) {
		 KillTimer(_hWnd, 1);
		 //Ű�Ŵ��� ������
		 IMAGEMANAGER->deleteAll();
		 IMAGEMANAGER->releaseSingleton();
		 KEYMANAGER->releaseSingleton();
		 IMAGEMANAGER->releaseSingleton();
		 SOUNDMANAGER->releaseSingleton();
		 INIDATAMANAGER->releaseSingleton();
		 EFFECTMANAGER->releaseSingleton();
		 TXTDATA->release();
	 }

 }
 void gameNode::update(void)
 {
	 InvalidateRect(_hWnd, NULL, false);
 }
 void gameNode::render()
 {

 }


LRESULT gameNode::MainProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
	{
		if (SUCCEEDED(g_pd3dDevice->BeginScene())) {
			//3D�׸��� ����
			g_pd3dDevice->Clear(												//�ĸ� ���۸� rgb(0,128,255) �� ä����
				0,
				NULL,															//�Ƹ� Ŭ���� ���� ���� ��Ʈ�ε� -Ȯ��
				D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,								//Z���۱��� �����ش�.
				D3DCOLOR_XRGB(0, 128, 255),
				1.0f,
				0);
			g_pd3dSurface->GetDC(&hdc);
			render();
			g_pd3dSurface->ReleaseDC(hdc);
			
			g_pd3dDevice->EndScene();
		}
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}
	break;

	case WM_MOUSEMOVE:

		ptMouse.x = static_cast<float>LOWORD(lParam);
		ptMouse.y = static_cast<float>HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hwnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hwnd, iMessage, wParam, lParam));
}