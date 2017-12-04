#include "stdafx.h"
#include "PixelCollisionTest.h"


HRESULT PixelCollisionTest::init(void)
{
	IMAGEMANAGER->addImage("BG", "sprites/pixel.bmp", WINSIZEX, WINSIZEY, FALSE, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("BALL", "sprites/ball.bmp", 100, 100, TRUE, RGB(255, 255, 255));

	ball = IMAGEMANAGER->findImage("BALL");
	x = WINSIZEX / 2 - 100;
	y = WINSIZEY / 2 + 110;
	rc = RectMakeCenter(x, y, ball->getWidth(), ball->getHeight());

	probeY = y + ball->getHeight() / 2;
	return S_OK;
}

void PixelCollisionTest::release(void)
{
}

void PixelCollisionTest::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) x -= 3.0f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) x += 3.0f;
	probeY = y + ball->getHeight() / 2;
	for (int i = probeY - 50; i < probeY + 50; i++) {
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("BG")->getMemDC(), x, i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		//ÇÈ¼¿Ã¼Å©
		if (!(r == 255 && g == 0 && b == 255)) {
			y = i - ball->getHeight() / 2;
			break;
		}
	}
	rc = RectMakeCenter(x, y, ball->getWidth(), ball->getHeight());
}

void PixelCollisionTest::render()
{
}

PixelCollisionTest::PixelCollisionTest()
{
}


PixelCollisionTest::~PixelCollisionTest()
{
}
