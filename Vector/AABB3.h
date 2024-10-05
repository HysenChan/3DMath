#pragma once
#include"Vector3.h"
#include"Matrix4x3.h"
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

	Vector3 corner(int i)const;
	void empty();//���AABB
	bool isEmpty() const;
	bool contains(const Vector3& p)const;//���һ�����Ƿ���AABB����
	void add(const Vector3& p);
	void add(const AABB3& box);

	void setToTransformedBox(const AABB3& box, const Matrix4x3& m);//�任AABB

	Vector3 closestPointTo(const Vector3& p)const;//����AABB�������������ĵ�

	//float rayIntersect(const Vector3& rayOrg, const Vector3& rayDelta, Vector3* returnNormal = 0)const;
};