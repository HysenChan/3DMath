#pragma once
#include"Vector3.h"
class Quaternion
{
public:
	float w, x, y, z;

	void identity() { w = 1.0f; x = y = z = 0.0f; }

	void setToRotateAboutX(float theta);//��x��
	void setToRotateAboutY(float theta);//��y��
	void setToRotateAboutZ(float theta);//��z��
	void setToRotateAboutAxis(const Vector3& axis, float theta);//��������

	float getRotationAngle() const;//��ȡ��ת��
	Vector3 getRotationAxis() const;//��ȡ��ת��

	Quaternion operator *(const Quaternion& a)const;//����*����Ԫ���Ĳ��
	Quaternion& operator *=(const Quaternion& a);//����*����Ԫ���Ĳ��

	void normalize();//��Ԫ���淶������
};

extern const Quaternion kQuaternionIdentity;
extern float dotProduct(const Quaternion& a, const Quaternion& b);//��Ԫ�����
extern Quaternion conjugate(const Quaternion& q);//��Ԫ������
extern Quaternion pow(const Quaternion& q, float exponent);//��Ԫ������