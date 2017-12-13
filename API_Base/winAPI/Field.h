#pragma once
#include "Astar.h"

class Field
{
private:
	ANode **FieldMap;
	Astar pathFinder;
public:
	void Init();
	Field();
	~Field();
};

