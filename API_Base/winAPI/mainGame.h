#pragma once
#include"gameNode.h"
#include "StarcraftScene.h"
#include "selectScene.h"
class mainGame :  public gameNode
{

private:

	gameNode* curScene;
	gameNode* selScene;
	gameNode* stcScene;

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

