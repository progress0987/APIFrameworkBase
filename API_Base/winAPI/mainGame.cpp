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
	IMAGEMANAGER->addFrameImage("좀비", g_pd3dDevice, "sprites/zombie.png", 44, 8);
	IMAGEMANAGER->addImage("테스트", g_pd3dDevice, "sprites/test.jpg");
	testx = 0;
	testy = 1;

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

 }
 //여기가 그려주는 곳
 void mainGame::render() 
 {
	 paint();
	 TIMEMANAGER->render(getMemDC());

 }

 void mainGame::paint()
 {
	 IMAGEMANAGER->findImage("테스트")->render(300, 300);
	 IMAGEMANAGER->findImage("좀비")->framerender(posx, posy, testx, testy);
	 //test1.framerender(posx, posy,testx, testy);
 }
