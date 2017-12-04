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
	hdc = GetDC(_hWnd);
	managerInit = false;
	return S_OK;
}
HRESULT gameNode::init(bool managerInit)
{
	hdc = GetDC(_hWnd);
	this->managerInit = managerInit;
	if (managerInit) {
		SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		TXTDATA->init();
	}
	return S_OK;
}
 void gameNode::release(void)
 {
	 if (managerInit) {
		 KillTimer(_hWnd, 1);
		 //키매니저 릴리즈
		 IMAGEMANAGER->deleteAll();
		 IMAGEMANAGER->releaseSingleton();
		 KEYMANAGER->releaseSingleton();
		 IMAGEMANAGER->releaseSingleton();
		 SOUNDMANAGER->releaseSingleton();
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
	HDC hdc;

	switch (iMessage)
	{
	
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &ps);
		this->render();

		EndPaint(hwnd, &ps);
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