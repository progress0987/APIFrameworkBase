#include "stdafx.h"
#include "mainGame.h"


RECT rtemp;
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
//초기화
HRESULT mainGame::init(void) 
{
	gameNode::init(true);

	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL) {			//디바이스를 생성하기 위한 D3D 객체 생성
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
	g_pD3D->CreateDevice(					//출력될 디바이스를 생성하는부분
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
//해제
 void mainGame::release(void)
 {//사용한 이미지도 릴리즈해줘야함
	 gameNode::release();
 }
 //연산~
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
 //여기가 그려주는 곳 - paint 후에 paintDC가 렌더됨 - 순서 바꿀시 주의할것
 void mainGame::render() 
 {
	 if (SUCCEEDED(g_pd3dDevice->BeginScene())) {
		 //3D그리기 시작
		 g_pd3dDevice->Clear(												//후면 버퍼를 rgb(0,128,255) 로 채워줌
			 0,
			 NULL,															//아마 클리어 해줄 범위 렉트인듯 -확인
			 D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,								//Z버퍼까지 지워준다.
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

 //모든 이미지들 로드
 void mainGame::LoadImages()
 {
	 IMAGEMANAGER->addFrameImage("좀비", g_pd3dDevice, "sprites/zombie.png", 44, 8);
	 IMAGEMANAGER->addFrameImage("사막맵타일", g_pd3dDevice, "sprites/DesertTiles.png", 16, 2);
 }

 //이미지들 처리
 void mainGame::paint()
 {
	 Desert.render();
	 IMAGEMANAGER->findImage("좀비")->centerframerender(WINSIZEX/2, WINSIZEY/2, testx, testy);
	 //test1.framerender(posx, posy,testx, testy);
 }

 //DC단에서 할 일 처리
 void mainGame::paintDC()
 {
	 //SetBkColor(hdc, TRANSPARENT);
	 TextOut(hdc, 500, 500, "테스트입니다", strlen("테스트입니다"));
	 TIMEMANAGER->render(hdc);
 }
