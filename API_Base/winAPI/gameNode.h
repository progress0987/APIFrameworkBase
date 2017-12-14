#pragma once
#include "image.h"
#include "inc\d3dx9.h"


#pragma comment(lib,"d3dx9.lib")

class gameNode
{

private:
	HDC hdc;
	bool managerInit;
	HRESULT initD3D(HWND _hwnd);
protected:
	LPDIRECT3D9					g_pD3D;
	LPDIRECT3DDEVICE9			g_pd3dDevice;
	LPDIRECT3DSURFACE9			g_pd3dSurface;
public:
	HRESULT init(void);
	HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	HDC getMemDC() { return hdc; }
	HDC getHDC() { return hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual~gameNode();
};

