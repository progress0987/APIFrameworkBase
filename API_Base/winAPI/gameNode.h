#pragma once
#include "image.h"
#include <d3dx9.h>

#pragma comment(lib,"d3dx9.lib")

static image* backBuffer = IMAGEMANAGER->addImage("backBuffer",WINSIZEX,WINSIZEY);


class gameNode
{

private:
	HDC hdc;
	bool managerInit;
	HRESULT initD3D(HWND _hwnd);
protected:
	LPDIRECT3D9					g_pD3D;						//D3D 디바이스를 생성할 D3D 객체 변수
	LPDIRECT3DDEVICE9			g_pd3dDevice;				//D3D 디바이스
	LPDIRECT3DSURFACE9			g_pd3dSurface;
public:


	HRESULT init(void);
	HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	image* getBackBuffer() { return backBuffer; }

	HDC getMemDC() { return /*backBuffer->getMemDC()*/hdc; }
	HDC getHDC() { return hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual~gameNode();
};

