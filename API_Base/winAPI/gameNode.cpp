#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}
HRESULT gameNode::init(void)
{
	//hdc = GetDC(_hWnd);
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

	//initD3D(_hWnd);
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
	ptScale = 1.f;
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
	short tmp;
	switch (iMessage)
	{
	
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
	{
		render();
	}
	break;

	case WM_MOUSEMOVE:

		ptMouse.x = static_cast<float>LOWORD(lParam);
		ptMouse.y = static_cast<float>HIWORD(lParam);
		break;

	case WM_MOUSEWHEEL://���콺 ��ũ��
		tmp = HIWORD(wParam);
		if (tmp > 0)ptScale += 0.1f;		//��
		else if (tmp < 0)ptScale -= 0.1f;	//�Ʒ�

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