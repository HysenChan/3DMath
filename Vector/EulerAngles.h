#pragma once
#include"Matrix4x3.h"
#include"RotationMatrix.h"
class Quaternion;
class EulerAngles
{
public:
	float heading;//绕y轴-Yaw
	float pitch;//绕x轴
	float bank;//绕z轴-Roll

	EulerAngles() {}

	EulerAngles(float h, float p, float b) :heading(h), pitch(p), bank(b) {}

	void canonize();//欧拉角限制范围

	void fromObjectToWorldMatrix(const Matrix4x3& m);//物体-》惯性
	void fromWorldToObjectMatrix(const Matrix4x3& m);//惯性-》物体
	void fromRotationMatrix(const RotationMatrix& m);//旋转矩阵（惯性-》物体）

	void fromObjectToInertialQuaternion(const Quaternion& q);//物体坐标系-》惯性坐标系 四元数-》欧拉角
	void fromInertialToObjectQuaternion(const Quaternion& q);//惯性坐标系-》物体坐标系 四元数-》欧拉角
};