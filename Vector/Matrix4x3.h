#pragma once
#include <math.h>

class Vector3;

class Matrix4x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void setRotate(int axis, float theta);//旋转矩阵
	void setupScale(const Vector3& s);//缩放矩阵
	void setupProject(const Vector3& n);//投影矩阵
	void setupReflect(int axis, float k);//镜像矩阵
	void setupReflect(const Vector3& n);
	//三维的
	void setupShear(int axis, float s, float t);//切边矩阵

	void zeroTranslation();
	void setTranslation(const Vector3& d);
	void setupTranslation(const Vector3& d);
};

Matrix4x3 operator *(const Matrix4x3& a, const Matrix4x3& b);//重载*运算符计算矩阵x矩阵

Vector3 operator *(const Vector3& p, const Matrix4x3& m);//（行向量）重载*运算符计算向量x矩阵

Vector3 operator *(const Matrix4x3& m, const Vector3& p);//（列向量）重载*运算符计算矩阵x向量

Matrix4x3& operator *=(Matrix4x3& a, const Matrix4x3& m);//重载*=运算符计算矩阵x矩阵

Vector3& operator*=(Vector3& p, const Matrix4x3& m);//（行向量）重载*=运算符计算向量x矩阵

Vector3& operator *=(const Matrix4x3& m, Vector3& p);//（列向量）重载*=运算符计算矩阵x向量

float determinant(const Matrix4x3& m);//矩阵的行列式
Matrix4x3 inverse(const Matrix4x3& m);//矩阵的逆

Vector3 getTranslation(const Matrix4x3& m);