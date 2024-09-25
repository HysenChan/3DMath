#pragma once
#include <math.h>

class Vector3;

class Matrix3x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;

	void setRotate(int axis, float theta);//��ת����
	void setupScale(const Vector3& s);//���ž���
	void setupProject(const Vector3& n);//ͶӰ����
	void setupReflect(int axis);//�������
	void setupReflect(const Vector3& n);//��ά��
	void setupShear(int axis, float s, float t);//�б߾���
};

Matrix3x3 operator *(const Matrix3x3& a, const Matrix3x3& b);//����*������������x����

Vector3 operator *(const Vector3& p, const Matrix3x3& m);//��������������*�������������x����

Vector3 operator *(const Matrix3x3& m, const Vector3& p);//��������������*������������x����

Matrix3x3& operator *=(Matrix3x3& a, const Matrix3x3& m);//����*=������������x����

Vector3& operator*=(Vector3& p, const Matrix3x3& m);//��������������*=�������������x����

Vector3& operator *=(const Matrix3x3& m, Vector3& p);//��������������*=������������x����

float determinant(const Matrix3x3& m);//���������ʽ
Matrix3x3 inverse(const Matrix3x3& m);//�������