#pragma once
//#include "gameNode.h"
//
//typedef void(*CALLBACK_FUNCTION)();
//class Action:public gameNode
//{
//private:
//
//	image* img;				//�̹���
//	float startX, startY;	//������ǥ
//	float endX, endY;		
//
//	float angle;			//����
//	float travelRange;		//�̵��Ÿ�
//	float worldTimeCount;	//
//	float time;
//
//	bool isMoving;
//
//	CALLBACK_FUNCTION callbackfunc;
//public:
//
//	HRESULT init(void);
//	void release(void);
//	void update(void);
//	void render();
//
//	void moveTo(image* image, float endx, float endy,float time);
//	void moveTo(image* image, float endx, float endy, float time, CALLBACK_FUNCTION cbfunc);
//
//	void moving();
//
//	bool getIsMoving() { return this->isMoving; }
//
//
//	Action();
//	~Action();
//};
//
