#pragma once

//버전 낮은 사람들을 위한 cMath 라이브러리 추가
#include <cmath>

#define DEC_TO_RAD 0.017453f // 1도에 대한 라디안 값
#define PI 3.141592654f
#define PI2 PI*2
#define FLOAT_EPSILON 0.001f // 실수에서 가장 작은 단위

namespace Util {
	//거리
	float getDistance(float startX,float startY, float endX, float endY);
	//각도
	float getAngle(float x1, float y1, float x2, float y2);
}


