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
		 posx -= 1.0f;
		 posy += 0.5f;
		 testy = 7;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		 posx += 1.0f;
		 posy -= 0.5f;
		 testy = 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		 posx -= 1.0f;
		 posy -= 0.5f;
		 testy = 1;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		 posx += 1.0f;
		 posy += 0.5f;
		 testy = 5;
	 }

	 if (KEYMANAGER->isStayKeyDown('W')) {
		 mainCam->y -= .5f;
	 }
	 if (KEYMANAGER->isStayKeyDown('S')) {
		 mainCam->y += .5f;
	 }
	 if (KEYMANAGER->isStayKeyDown('A')) {
		 mainCam->x -= 1.f;
	 }
	 if (KEYMANAGER->isStayKeyDown('D')) {
		 mainCam->x += 1.f;
	 }

 }
 //여기가 그려주는 곳
 void mainGame::render() 
 {
	 Desert.render();
	 paint();
	 TIMEMANAGER->render(getMemDC());

 }

 void mainGame::LoadImages()
 {
	 IMAGEMANAGER->addFrameImage("좀비", g_pd3dDevice, "sprites/zombie.png", 44, 8);
	 IMAGEMANAGER->addImage("테스트", g_pd3dDevice, "sprites/test.jpg");
	 IMAGEMANAGER->addFrameImage("사막맵타일", g_pd3dDevice, "sprites/DesertTiles.png", 16, 2);
 }

 void mainGame::paint()
 {
	 IMAGEMANAGER->findImage("테스트")->centerrender(300, 300);
	 IMAGEMANAGER->findImage("좀비")->centerframerender(posx, posy, testx, testy);
	 //test1.framerender(posx, posy,testx, testy);
 }
