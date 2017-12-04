#pragma once
#include "gameNode.h"


//이동 패턴
struct MoveSet {
	BezierPoint destList[4];//3차곡선까지만 하는걸로. 부족한 무브셋은 무브셋을 여러번 사용하는걸로 해결
	vector<BezierPoint> moveList;
};
//

class enemy :public gameNode
{
protected:
	image* bodyImg;
	vector<image*> bodyParts;
	RECT rc;


	int curFrameX;
	int curFrameY;

	int count;
	int fireCount;
	int rndFireCount;
	vector<MoveSet> phase;
	int HP;
public:

	HRESULT init(void);
	HRESULT init(const char* img, POINT position);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	void move();
	void draw();
	void setPhase(int index, BezierPoint* movepoints, int frames);

	bool bulletCountFire();

	inline RECT getRect() { return rc; }

	BezierPoint POnCubicBezier(BezierPoint* cp, float t);
	void computeBezier(BezierPoint* cp, int numOfPoints, int index);


	enemy();
	~enemy();
};