#include "Vector3.h"
#include "Matrix3x3.h"
#include "MathUtil.h"
#include "assert.h"

void Matrix3x3::setupScale(const Vector3& s)
{
	m11 = s.x, m12 = 0.0f, m13 = 0.0f;
	m21 = 0.0f, m22 = s.y, m23 = 0.0f;
	m31 = 0.0f, m32 = 0.0f, m33 = s.z;
}

// axis
// 1->x÷·
// 2->y÷·
// 3->z÷·
void Matrix3x3::setRotate(int axis, float theta)
{
	float s, c;
	sinCos(&s, &c, theta);

	switch (axis)
	{
	case 1:
		m11 = 1.0f, m12 = 0.0f, m13 = 0.0f;
		m21 = 0.0f, m22 = c, m23 = s;
		m31 = 0.0f, m32 = -s, m33 = c;
		break;
	case 2:
		m11 = c, m12 = 0.0f, m13 = -s;
		m21 = 0.0f, m22 = 1.0f, m23 = 0.0f;
		m31 = s, m32 = 0.0f, m33 = c;
		break;
	case 3:
		m11 = c, m12 = s, m13 = 0.0f;
		m21 = -s, m22 = c, m23 = 0.0f;
		m31 = 0.0f, m32 = 0.0f, m33 = 1.0f;
		break;
	default:
		assert(false);
		break;
	}
}

Matrix3x3 operator*(const Matrix3x3& a, const Matrix3x3& b)
{
	Matrix3x3 r;

	r.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	r.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	r.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

	r.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	r.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	r.m23 = a.m21 * b.m11 + a.m22 * b.m23 + a.m23 * b.m33;

	r.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	r.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	r.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;

	return r;
}

Matrix3x3& operator *=(Matrix3x3& a, const Matrix3x3& m)
{
	a = a * m;
	return a;
}

Vector3 operator*(const Vector3& p, const Matrix3x3& m)
{
	return Vector3(
		p.x * m.m11 + p.y * m.m21 + p.z * m.m31,
		p.x * m.m12 + p.y * m.m22 + p.z * m.m32,
		p.x * m.m13 + p.y * m.m23 + p.z * m.m33
	);
}


Vector3& operator *=(Vector3& p, const Matrix3x3& m)
{
	p = p * m;
	return p;
}


Vector3 operator*(const Matrix3x3& m, const Vector3& p)
{
	return Vector3(
		p.x * m.m11 + p.y * m.m12 + p.z * m.m13,
		p.x * m.m21 + p.y * m.m22 + p.z * m.m23,
		p.x * m.m31 + p.y * m.m32 + p.z * m.m33
	);
}

Vector3& operator *=(const Matrix3x3& m, Vector3& p)
{
	p = m * p;
	return p;
}