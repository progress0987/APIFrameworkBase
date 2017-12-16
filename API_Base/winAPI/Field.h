#pragma once
#include "gameNode.h"

#define TILEHEIGHT 64
#define TILEWIDTH TILEHEIGHT*2


#define TILENUMX 15
#define TILENUMY 15


struct tile {
	RECT rc;
	POINT pos;
	POINT index;
};

class Field
{
private:
	Camera * cam;
	D2DImage* tileset;
	tile map[TILENUMX][TILENUMY];
public:
	void init();
	void update();
	void render();
	void setCam(Camera* cam) { this->cam = cam; }
	Field();
	~Field();
};

