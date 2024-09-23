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

Matrix3x3 operator *(const Matrix3x3& a, const Matrix3x3& b);//重载*运算符计算矩阵x矩阵

Vector3 operator *(const Vector3& p, const Matrix3x3& m);//（行向量）重载*运算符计算向量x矩阵

Matrix3x3& operator *=(Matrix3x3& a, const Matrix3x3& m);//重载*=运算符计算矩阵x矩阵

Vector3& operator*=(Vector3& p, const Matrix3x3& m);//（行向量）重载*=运算符计算向量x矩阵