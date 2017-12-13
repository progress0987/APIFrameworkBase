#pragma once
#include"gameNode.h"
#include "D2DImage.h"
class mainGame :  public gameNode
{

private:
	D2DImage test1;
	float posx=300.f, posy=300.f;
	int testx=0,testy = 0;
	int tick = 0;

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	void paint();

	mainGame();
	~mainGame();
};

