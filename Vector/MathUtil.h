#pragma once
#include<math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

extern float wrapPi(float theta);
extern float safeAcos(float x);//安全的反三角函数

inline void sinCos(float* returnSin, float* returnCos, float theta)
{
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}