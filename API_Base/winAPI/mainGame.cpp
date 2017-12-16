#include "stdafx.h"
#include "mainGame.h"


RECT rtemp;
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
//�ʱ�ȭ
HRESULT mainGame::init(void) 
{
	gameNode::init(true);

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

	LoadImages();

	testx = 0;
	testy = 1;
	mainCam = new Camera;
	mainCam->x = 0;
	mainCam->y = 0;
	Desert.setCam(mainCam);
	Desert.init();

	return S_OK;
}
//����
 void mainGame::release(void)
 {//����� �̹����� �������������
	 gameNode::release();
 }
 //����~
 void mainGame::update(void)
 {
	 gameNode::update();
	 tick++;
	 if (tick % 20 == 0) {
		 testx++;
		 if (testx > 11) testx = 4;
		 //if (testx > 21) testx = 12;
		 //if (testx > 3) testx = 0;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		 mainCam->x -= MOVESPEEDX;
		 mainCam->y += MOVESPEEDY;
		 testy = 7;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		 mainCam->x += MOVESPEEDX;
		 mainCam->y -= MOVESPEEDY;
		 testy = 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		 mainCam->x -= MOVESPEEDX;
		 mainCam->y -= MOVESPEEDY;
		 testy = 1;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		 mainCam->x += MOVESPEEDX;
		 mainCam->y += MOVESPEEDY;
		 testy = 5;
	 }


 }
 //���Ⱑ �׷��ִ� �� - paint �Ŀ� paintDC�� ������ - ���� �ٲܽ� �����Ұ�
 void mainGame::render() 
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
		 PatBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		 paint();
		 g_pd3dSurface->GetDC(&hdc);
		 paintDC();
		 g_pd3dSurface->ReleaseDC(hdc);

		 g_pd3dDevice->EndScene();
	 }
	 g_pd3dDevice->Present(NULL, NULL, NULL, NULL);



 }

 //��� �̹����� �ε�
 void mainGame::LoadImages()
 {
	 IMAGEMANAGER->addFrameImage("����", g_pd3dDevice, "sprites/zombie.png", 44, 8);
	 IMAGEMANAGER->addFrameImage("�縷��Ÿ��", g_pd3dDevice, "sprites/DesertTiles.png", 16, 2);
 }

 //�̹����� ó��
 void mainGame::paint()
 {
	 Desert.render();
	 IMAGEMANAGER->findImage("����")->centerframerender(WINSIZEX/2, WINSIZEY/2, testx, testy);
	 //test1.framerender(posx, posy,testx, testy);
 }

 //DC�ܿ��� �� �� ó��
 void mainGame::paintDC()
 {
	 //SetBkColor(hdc, TRANSPARENT);
	 TextOut(hdc, 500, 500, "�׽�Ʈ�Դϴ�", strlen("�׽�Ʈ�Դϴ�"));
	 TIMEMANAGER->render(hdc);
 }
