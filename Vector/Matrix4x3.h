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

	void setRotate(int axis, float theta);//��ת����
	void setupScale(const Vector3& s);//���ž���
	void setupProject(const Vector3& n);//ͶӰ����
	void setupReflect(int axis, float k);//�������
	void setupReflect(const Vector3& n);
	//��ά��
	void setupShear(int axis, float s, float t);//�б߾���

	void zeroTranslation();
	void setTranslation(const Vector3& d);
	void setupTranslation(const Vector3& d);
};

Matrix4x3 operator *(const Matrix4x3& a, const Matrix4x3& b);//����*������������x����

Vector3 operator *(const Vector3& p, const Matrix4x3& m);//��������������*�������������x����

Vector3 operator *(const Matrix4x3& m, const Vector3& p);//��������������*������������x����

Matrix4x3& operator *=(Matrix4x3& a, const Matrix4x3& m);//����*=������������x����

Vector3& operator*=(Vector3& p, const Matrix4x3& m);//��������������*=�������������x����

Vector3& operator *=(const Matrix4x3& m, Vector3& p);//��������������*=������������x����

float determinant(const Matrix4x3& m);//���������ʽ
Matrix4x3 inverse(const Matrix4x3& m);//�������

Vector3 getTranslation(const Matrix4x3& m);