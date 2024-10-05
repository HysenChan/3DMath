#pragma once
#include"Vector3.h"
class AABB3
{
public:
	Vector3 min;
	Vector3 max;

	Vector3 size() const { return max - min; }
	float xSize() { return max.x - min.x; }
	float ySize() { return max.y - min.y; }
	float zSize() { return max.z - min.z; }

	Vector3 center() { return (min + max) * 0.5f; }
};