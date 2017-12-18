#pragma once
#include "gameNode.h"

#define TILEHEIGHT 64
#define TILEWIDTH TILEHEIGHT*2


#define TILENUMX 50
#define TILENUMY 50

enum TILE_TYPE
{
	TILE_TYPE_EMPTY,		//��Ÿ��(�������� �ִ°�)
	TILE_TYPE_START,		//����
	TILE_TYPE_END,			//��
	TILE_TYPE_WALL			//��ֹ�
};
struct tile {
	RECT rc;
	POINT pos;
	POINT index;

	bool walkable;			//���������̛X��
	bool listOn;			//���¸���Ʈ�� �߰� �Ǿ���

	int F = 0;
	int G = 0;
	int H = 0;
	char str[128];
	tile* parent;		//�θ�Ÿ�� �ּ�
	TILE_TYPE type;//Ÿ�� �Ӽ�

};

class Field
{
private:
	Camera * cam;
	D2DImage* tileset;
	tile map[TILENUMX][TILENUMY];
	//FLOAT scale;
public:
	void init();
	void update();
	void render();
	void setCam(Camera* cam) { this->cam = cam; }
	Field();
	~Field();
};

