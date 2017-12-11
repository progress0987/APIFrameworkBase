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
	test1.init(g_pd3dDevice);
	test1.setImage("sprites/test.jpg");
	test2.init(g_pd3dDevice);
	test2.setImage("sprites/battle.bmp",TRUE,16,1,0xffff00ff);
	test3.init(g_pd3dDevice);
	test3.setImage("sprites/skill.png",TRUE,5,3,0xff000000);

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
	 if (tick % 10 == 0) {
		 testx++;
		 if (testx > test3.getFrameMaxX()) {
			 testx = 0; testy++;
			 if (testy > test3.getFrameMaxY()) {
				 testx = 0; testy = 0;
			 }
		 }
	 }
	 if (tick % 30 == 0) {
		 test++;
		 if (test > test2.getFrameMaxX()) {
			 test = 0;
		 }
	 }
	 if (tick % 10 == 0) {
		 testangle += 0.03f;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		 posx -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		 posx += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		 posy -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		 posy += 3;
	 }
	 if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		 trigger = !trigger;
	 }

 }
 //여기가 그려주는 곳
 void mainGame::render() 
 {
	 HDC curDC;
	 //g_pd3dSurface->GetDC(&curDC);
	 test1.render(300, 300);
	 test1.rotatedrender(200,200,testangle);

	 //test1.render(500, 500);

	 test2.rotatedframerender(WINSIZEX/2,WINSIZEY/2,test,0,testangle);
	 //test3.render();
	 test3.rotatedframerender(posx, posy, testx, testy,testangle);
	 //TIMEMANAGER->render(curDC);
 }