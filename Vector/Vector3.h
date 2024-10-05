#pragma once
#include <math.h>
class Vector3
{
public:
	float x, y, z;

	Vector3() {}
	Vector3(const Vector3& a) :x(a.x), y(a.y), z(a.z) {}
	Vector3(float nx, float ny, float nz) :x(nx), y(ny), z(nz) {}

	void zero() {
		x = y = z = 0.0f;
	}

	Vector3 operator -() const { return Vector3(-x, -y, -z); }//重载-号计算负向量

	Vector3 operator *(float a)const//重载*计算标量和向量的乘法
	{
		return Vector3(x * a, y * a, z * a);
	}

	Vector3 operator *=(float a)
	{
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3 operator /(float a)const//重载/计算标量和向量的除法
	{
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	Vector3 operator /=(float a)
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	Vector3 operator +(const Vector3& a) const//重载+计算向量和向量的加法
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator +=(const Vector3& a)
	{
		x += a.x; y += a.y; z += a.z;
		return *this;
	}

	Vector3 operator -(const Vector3& a) const//重载-计算向量和向量的减法
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	Vector3 operator -=(const Vector3& a)
	{
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	void normalize()//标准化向量
	{
		float magSq = x * x + y * y + z * z;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	float operator *(const Vector3& a) const//重载*计算向量和向量的点乘
	{
		return x * a.x + y * a.y + z * a.z;
	}
};

inline float vectorMag(const Vector3& a)//计算向量的模
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline Vector3 operator *(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

inline float distance(const Vector3& a, const Vector3& b)//计算向量和向量之间的距离
{
	/*float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx * dx + dy * dy + dz * dz);*/
	return vectorMag(a - b);
}

inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

extern const Vector3 kZeroVector;