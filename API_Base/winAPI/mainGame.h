#pragma once
#include"gameNode.h"
#include "D2DImage.h"
class mainGame :  public gameNode
{

private:
	D2DImage test1;
	D2DImage test2;
	D2DImage test3;
	int posx=300, posy=300;
	int testx=0,testy = 0;
	int test = 0;
	int tick = 0;
	float testangle = 0.0f;
	bool trigger = false;

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

