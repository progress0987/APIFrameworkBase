// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
// C++ ��Ÿ�� ��� �����Դϴ�.
//#include<iostream>


//���� ���� STL
#include<string>
#include<vector>
#include<list>
#include<map>

#include"commonMacroFunction.h"
#include"randomFuction.h"
#include"KeyManager.h"
#include"utils.h"
#include"imageManager.h"
#include "timeManager.h"
#include "txtData.h"
#include "soundManager.h"
#include "iniDataManager.h"
#include "effectManager.h"

#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "winmm.lib")

using namespace std;
using namespace Util;
//====================================
// ##���� ���� ������� ��⿡ �߰�!!
//====================================


//====================================
//   ##������ �� ##(������ �ʱ�ȭ ����)
//====================================

#define WINNAME (LPTSTR)(TEXT("API BASE"))
#define WINSTARTX 100
#define WINSTARTY 50
#define WINSIZEX  1280
#define WINSIZEY  720
#define WINSTYLE  WS_CAPTION|WS_SYSMENU



//�����Լ� ������
#define RND				randomFunction::getSingleton()
//Ű�Ŵ���
#define KEYMANAGER		KeyManager::getSingleton()

#define IMAGEMANAGER	imageManager::getSingleton()
#define TIMEMANAGER		timeManager::getSingleton()
#define EFFECTMANAGER	effectManager::getSingleton()

#define SOUNDMANAGER	soundManager::getSingleton()
#define TXTDATA			txtData::getSingleton()

#define INIDATAMANAGER	iniDataManager::getSingleton()
//===============================================
//   ##��ũ�� �Լ� ##(���ΰ��� ������ �κп��� ���)
//===============================================

#define SAFE_DELETE(p)  {if(p) {delete(p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)  {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p) {if(p){(p)->release();(p)=nullptr;}}

//=================================================
//   ##�������� ## (�ν��Ͻ�, ������ �ڵ�, ���콺 ��ǥ)
//=================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT ptMouse;
extern FLOAT ptScale;

struct Camera {
	DOUBLE x, y;
	DOUBLE offsetX, offsetY;
};
extern LPDIRECT3D9					g_pD3D;						//D3D ����̽��� ������ D3D ��ü ����
extern LPDIRECT3DDEVICE9			g_pd3dDevice;				//D3D ����̽�
extern LPDIRECT3DSURFACE9			g_pd3dSurface;
extern HDC							hdc;						//DCŬ����


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
