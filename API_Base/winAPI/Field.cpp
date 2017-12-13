#include "stdafx.h"
#include "Field.h"


void Field::Init()
{
	ZeroMemory(*FieldMap, 200 * 200 * sizeof(ANode));
	pathFinder.setMap(FieldMap);
}

Field::Field()
{
}


Field::~Field()
{
}
