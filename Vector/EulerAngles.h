#pragma once
#include"Matrix4x3.h"
#include"RotationMatrix.h"
class EulerAngles
{
public:
	float heading;
	float pitch;
	float bank;

	EulerAngles() {}

	EulerAngles(float h, float p, float b) :heading(h), pitch(p), bank(b) {}

	void canonize();//欧拉角限制范围

	void fromObjectToWorldMatrix(const Matrix4x3& m);//物体-》惯性
	void fromWorldToObjectMatrix(const Matrix4x3& m);//惯性-》物体
	void fromRotationMatrix(const RotationMatrix& m);//旋转矩阵（惯性-》物体）
};