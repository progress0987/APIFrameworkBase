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
 //���Ⱑ �׷��ִ� ��
 void mainGame::render() 
 {
	 Desert.render();
	 paint();
	 TIMEMANAGER->render(getMemDC());

 }

 void mainGame::LoadImages()
 {
	 IMAGEMANAGER->addFrameImage("����", g_pd3dDevice, "sprites/zombie.png", 44, 8);
	 IMAGEMANAGER->addImage("�׽�Ʈ", g_pd3dDevice, "sprites/test.jpg");
	 IMAGEMANAGER->addFrameImage("�縷��Ÿ��", g_pd3dDevice, "sprites/DesertTiles.png", 16, 2);
 }

 void mainGame::paint()
 {
	 IMAGEMANAGER->findImage("�׽�Ʈ")->centerrender(300, 300);
	 IMAGEMANAGER->findImage("����")->centerframerender(posx, posy, testx, testy);
	 //test1.framerender(posx, posy,testx, testy);
 }
