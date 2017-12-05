#pragma once
#include"gameNode.h"
class mainGame :  public gameNode
{

private:
	RECT sel1, sel2, sel3, sel4;
	int offsetX, offsetY;
	int curSel;
	bool selected;
	int selectcount;
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

