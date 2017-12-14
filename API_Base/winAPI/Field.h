#pragma once
#include "gameNode.h"


#define TILEHEIGHT 32
#define TILEWIDTH 64


#define TILENUMX 50
#define TILENUMY 50


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

