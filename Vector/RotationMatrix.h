#pragma once
#include"Vector3.h"
class RotationMatrix
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	void identity();

	Vector3 inertialToObject(const Vector3& v)const;//��������ϵ-����������ϵ
	Vector3 objectToInertial(const Vector3& v)const;//��������ϵ-����������ϵ
};