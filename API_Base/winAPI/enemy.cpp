#include "stdafx.h"
#include "enemy.h"


HRESULT enemy::init(void)
{
	return S_OK;
}

HRESULT enemy::init(const char * img, POINT position)
{
	curFrameX = curFrameY = 0;
	count = fireCount = 0;
	rndFireCount = RND->getFromIntTo(1, 1000);
	this->bodyImg = IMAGEMANAGER->findImage(img);
	rc = RectMakeCenter(position.x, position.y, this->bodyImg->getFrameWidth(), this->bodyImg->getFrameHeight());

	return S_OK;
}


void enemy::release(void)
{
}

void enemy::update(void)
{
	count++;

	if (count % 2 == 0) {
		//프레임 변형부분 - 수정
		bodyImg->setFrameX(bodyImg->getFrameX() + 1);
		curFrameX++;
		if (curFrameX > bodyImg->getMaxFrameX()) curFrameX = 0;
	}
}

void enemy::render()
{
	draw();
}

void enemy::move()
{
}

void enemy::draw()
{
	bodyImg->frameRender(getMemDC(), rc.left, rc.top, curFrameX, curFrameY);
	//몸이 여러개일경우 더 그려줌
}

void enemy::setPhase(int index, BezierPoint * movepoints, int frames)
{
	for (int i = 0; i < 4; i++) {
		//에러날확률있음
		phase[index].moveList[i] = movepoints[i];
	}
	int tempframes;
	if (frames < (sizeof(BezierPoint) * 4)) {
		tempframes = sizeof(BezierPoint) * 4;
	}
	else {
		tempframes = frames;
	}

	computeBezier(movepoints, tempframes, index);

}

bool enemy::bulletCountFire()
{
	fireCount++;
	//랜덤으로 총알 발사인듯
	if (fireCount%rndFireCount == 0) {
		fireCount = 0;
		rndFireCount = RND->getFromIntTo(1, 1000);
		return true;
	}
	return false;
}


BezierPoint enemy::POnCubicBezier(BezierPoint * cp, float t)
{
	float ax, bx, cx;
	float ay, by, cy;

	float tSQ, tCB;
	BezierPoint result;

	cx = 3.0f* (cp[1].x - cp[0].x);
	bx = 3.0f*(cp[2].x - cp[1].x) - cx;
	ax = cp[3].x - cp[0].x - cx - bx;

	cy = 3.0f* (cp[1].y - cp[0].y);
	by = 3.0f*(cp[2].y - cp[1].y) - cy;
	ay = cp[3].y - cp[0].y - cy - by;

	tSQ = t*t;
	tCB = t*t*t;
	result.x = (ax*tCB) + (bx*tSQ) + cx*t + cp[0].x;
	result.y = (ay*tCB) + (by*tSQ) + cy*t + cp[0].y;

	return result;
}

void enemy::computeBezier(BezierPoint* cp, int numOfPoints, int index)
{
	float dt;
	dt = 1.0f / (numOfPoints - 1);

	for (int i = 0; i < numOfPoints; i++) {
		phase[index].moveList.push_back(POnCubicBezier(cp, i*dt));
	}
}

enemy::enemy()
{
}


enemy::~enemy()
{
}
