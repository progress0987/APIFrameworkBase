#pragma once
#include "gameNode.h"

class Animation;

class Effect : public gameNode
{
protected:
	int				x;					//����Ʈ ��ǥ��ġ Left
	int				y;					//����Ʈ ��ǥ��ġ top

	D2DImage*		effectImage;		//����Ʈ �̹���
	Animation*		effectAnimation;	//����Ʈ �ִϸ��̼�
	BOOL			isRunning;			//����Ʈ Ȱ��ȭ ����
	float			elapsedTime;		//����Ʈ ����ð�

public:

	virtual HRESULT init(D2DImage* effectImage, int frameX, int frameY, int fps, float elapsedTime);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);

	virtual void killEffect(void);

	BOOL getIsRunning(void) { return isRunning; }

	Effect();
	~Effect();
};