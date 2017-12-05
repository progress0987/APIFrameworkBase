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
	IMAGEMANAGER->addImage("BG", "sprites/171205/selectBG.bmp", 304*2, 224*2, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("SEL1", "sprites/171205/sel1.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("SEL2", "sprites/171205/sel2.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("SEL3", "sprites/171205/sel3.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("SEL4", "sprites/171205/sel4.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("PICK1", "sprites/171205/pick1.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("PICK2", "sprites/171205/pick2.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("PICK3", "sprites/171205/pick3.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("PICK4", "sprites/171205/pick4.bmp", 128, 240, false, 0);
	IMAGEMANAGER->addImage("P1", "sprites/171205/selp1.bmp", 53, 38, true, RGB(255, 255, 255));
	offsetX = offsetY = 100;
	sel1 = RectMake(34 + offsetX, 144 + offsetY, 128, 240);
	sel2 = RectMake(172 + offsetX, 144 + offsetY, 128, 240);
	sel3 = RectMake(306 + offsetX, 144 + offsetY, 128, 240);
	sel4 = RectMake(442 + offsetX, 144 + offsetY, 128, 240);
	curSel = -1;
	selected = false;

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
	 if (PtInRect(&sel1, ptMouse)) {
		 curSel = 0;
	 }
	 else if (PtInRect(&sel2, ptMouse)) {
		 curSel = 1;
	 }
	 else if (PtInRect(&sel3, ptMouse)) {
		 curSel = 2;
	 }
	 else if (PtInRect(&sel4, ptMouse)) {
		 curSel = 3;
	 }
	 else {
		 curSel = -1;
	 }
	 if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
		 if (!selected) {
			 selected = true;
			 selectcount = 0;
		 }
	 }
	 if (selected) {
		 selectcount++;
		 if (selectcount > 100) {
			 selected = false;
		 }

	 }

 }
 //여기가 그려주는 곳
 void mainGame::render() 
 {
	 HBRUSH brush;
	 HBITMAP hBitmap, OldBitmap;
	 /////////////////////////////////////건들지 말것(?)//////////////////////////////////////////////
	 PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	 //////////////////////////////////////////////////////////////////////////////////////////////
	 //getmemdc에 넣어줌

	 IMAGEMANAGER->findImage("BG")->render(getMemDC(),offsetX,offsetY);
	 TIMEMANAGER->render(getMemDC());
	 if (curSel != -1) {
		 switch (curSel) {
		 case 0:
			 IMAGEMANAGER->findImage("P1")->render(getMemDC(), 69+offsetX, 95+offsetY);
			 if (selected) {
				 IMAGEMANAGER->findImage("PICK1")->render(getMemDC(), sel1.left, sel1.top);
			 }
			 else {
				 IMAGEMANAGER->findImage("SEL1")->render(getMemDC(), sel1.left, sel1.top);
			 }
			 break;
		 case 1:
			 IMAGEMANAGER->findImage("P1")->render(getMemDC(), 204 + offsetX, 93 + offsetY);
			 if (selected) {
				 IMAGEMANAGER->findImage("PICK2")->render(getMemDC(), sel2.left, sel2.top);
			 }
			 else {
				 IMAGEMANAGER->findImage("SEL2")->render(getMemDC(), sel2.left, sel2.top);
			 }
			 break;
		 case 2:
			 IMAGEMANAGER->findImage("P1")->render(getMemDC(), 342 + offsetX, 95 + offsetY);
			 if (selected) {
				 IMAGEMANAGER->findImage("PICK3")->render(getMemDC(), sel3.left, sel3.top);
			 }
			 else {
				 IMAGEMANAGER->findImage("SEL3")->render(getMemDC(), sel3.left, sel3.top);
			 }
			 break;
		 case 3:
			 IMAGEMANAGER->findImage("P1")->render(getMemDC(), 482 + offsetX, 93 + offsetY);
			 if (selected) {
				 IMAGEMANAGER->findImage("PICK4")->render(getMemDC(), sel4.left, sel4.top);
			 }
			 else {
				 IMAGEMANAGER->findImage("SEL4")->render(getMemDC(), sel4.left, sel4.top);
			 }
			 break;
		 }
	 }

	 /////////////////////그려주는부분 - 건들지말것//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }