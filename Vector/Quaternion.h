#pragma once
#include"Vector3.h"

class RotationMatrix;
class EulerAngles;
class Quaternion
{
public:
	float w, x, y, z;

	void identity() { w = 1.0f; x = y = z = 0.0f; }

	void setToRotateAboutX(float theta);//绕x轴
	void setToRotateAboutY(float theta);//绕y轴
	void setToRotateAboutZ(float theta);//绕z轴
	void setToRotateAboutAxis(const Vector3& axis, float theta);//绕任意轴

	float getRotationAngle() const;//获取旋转角
	Vector3 getRotationAxis() const;//获取旋转轴

	Quaternion operator *(const Quaternion& a)const;//重载*做四元数的叉乘
	Quaternion& operator *=(const Quaternion& a);//重载*做四元数的叉乘

	void normalize();//四元数规范化操作

	void fromRotationMatrix(const RotationMatrix& m);//从旋转矩阵到四元数

	void setToRotateObjectToInertial(const EulerAngles& orientation);//从欧拉角到四元数（物体坐标系-》惯性坐标系）
	void setToRotateInertialToObject(const EulerAngles& orientation);//从欧拉角到四元数（惯性坐标系-》物体坐标系）
};

extern const Quaternion kQuaternionIdentity;
extern float dotProduct(const Quaternion& a, const Quaternion& b);//四元数点乘
extern Quaternion conjugate(const Quaternion& q);//四元数共轭
extern Quaternion pow(const Quaternion& q, float exponent);//四元数的幂
extern Quaternion slerp(const Quaternion& q0, const Quaternion& q1, float t);//四元数插值