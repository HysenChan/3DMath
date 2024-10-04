#pragma once
#include"Matrix4x3.h"
#include"RotationMatrix.h"
class EulerAngles
{
public:
	float heading;//��y��-Yaw
	float pitch;//��x��
	float bank;//��z��-Roll

	EulerAngles() {}

	EulerAngles(float h, float p, float b) :heading(h), pitch(p), bank(b) {}

	void canonize();//ŷ�������Ʒ�Χ

	void fromObjectToWorldMatrix(const Matrix4x3& m);//����-������
	void fromWorldToObjectMatrix(const Matrix4x3& m);//����-������
	void fromRotationMatrix(const RotationMatrix& m);//��ת���󣨹���-�����壩
};