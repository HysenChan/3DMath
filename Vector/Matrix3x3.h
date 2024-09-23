#pragma once
#include <math.h>

class Vector3;

class Matrix3x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
};

Matrix3x3 operator *(const Matrix3x3& a, const Matrix3x3& b);//����*������������x����

Vector3 operator *(const Vector3& p, const Matrix3x3& m);//��������������*�������������x����

Matrix3x3& operator *=(Matrix3x3& a, const Matrix3x3& m);//����*=������������x����

Vector3& operator*=(Vector3& p, const Matrix3x3& m);//��������������*=�������������x����