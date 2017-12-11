#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>														//dx9 �� ����ϴµ� ������ - ����ִ� ���̺귯���� ������ �Űܼ� �߰�������.
//#include "stdafx.h"
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

//http://ryuschool.tistory.com/entry/DirectX%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%9D%B4%EB%AF%B8%EC%A7%80-%ED%8C%8C%EC%9D%BC-%EB%9D%84%EC%9A%B0%EA%B8%B0
//http://3dapi.com/bs11_2d_basic/ ****** ���� ������

//��������
//g�� �����ϴ°� �۷ι�(����)

static LPDIRECT3D9					g_pD3D = NULL;						//D3D ����̽��� ������ D3D ��ü ����
static LPDIRECT3DDEVICE9			g_pd3dDevice = NULL;					//������ ������ ���� ���� - �������� ����ϱ����� ������ ����
////��������Ʈ
//static LPD3DXSPRITE					g_pd3dSprite = NULL;
////�̹����� �ҷ����� ���ؼ� ���
//static LPDIRECT3DTEXTURE9			g_tex = NULL;
int g_width, g_height;



HRESULT InitD3D(HWND hWnd) {
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL) {			//����̽��� �����ϱ� ���� D3D ��ü ����
		return E_FAIL;
	}
	D3DDISPLAYMODE d3ddm;
	g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
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
	//////////////////�̹����ҷ�����////////////
	D3DXIMAGE_INFO info;					//�̹��� �ҷ����°�
	D3DXIMAGE_INFO next;
	//����̽��� �ؽ��� �ҷ���
	D3DXCreateSprite(g_pd3dDevice, &g_pd3dSprite);

	if (FAILED(D3DXCreateTextureFromFileEx(
		g_pd3dDevice,						//��µ� ����̽�(HDC�� ����ѵ�)
		_T("sprites/test.jpg"),				//�����̸�(�ּ�)
		D3DX_DEFAULT_NONPOW2,				//��		��ü���Ҷ���0 �Ǵ� D3DX_DEFAULT�� ���
		D3DX_DEFAULT_NONPOW2,				//����		��
		1,									//�ӷ��� �̶�� �� - 2D������ ������ 1
		0,
		D3DFMT_UNKNOWN,					//���Ϸκ��� ������ �������°�, D3DFMT_UNKNOWN�����ϸ� �ҽ��� ����������� ����:D3DFMT_A8B8G8R8
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		NULL,								//�÷�Ű - �ش� ���� ��������ʴ´�(�����ε�)
		&info,
		NULL,
		&g_tex))) return E_FAIL;
	else {
		g_width = info.Width;
		g_height = info.Height;
	}
	return S_OK;														//����̽� �������� ó�� �Ϸ�
}
//������
void release() {
	if (g_pd3dDevice != NULL) {
		g_pd3dDevice->Release();
	}
	if (g_pD3D != NULL) {
		g_pD3D->Release();
	}
}

HRESULT addImage() {
	HRESULT hr = D3DXCreateTextureFromFileEx(
		g_pd3dDevice				// ����̽� ������
		, m_TexName[i]				// �ؽ�ó �̸�
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x0000001
		, 0x0000001
		, 0x00FFFFFF				// �÷� Ű
		, &m_Img[i]					// �ؽ�ó �������̼�
		, NULL
		, &m_Tex[i]					// �ؽ�ó ������
	);

	return S_OK;
}