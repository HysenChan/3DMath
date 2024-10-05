#include"Quaternion.h"
#include<math.h>
#include<assert.h>
#include"MathUtil.h"
#include"RotationMatrix.h"
#include"EulerAngles.h"

const Quaternion kQuaternionIdentity = { 1.0f,0.0f,0.0f,0.0f };

void Quaternion::setToRotateAboutX(float theta)
{
	float thetaOver2 = theta * 0.5f;

	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = 0.0f;
	z = 0.0f;
}

void Quaternion::setToRotateAboutY(float theta)
{
	float thetaOver2 = theta * 0.5f;

	w = cos(thetaOver2);
	x = 0.0f;
	y = sin(thetaOver2);
	z = 0.0f;
}

void Quaternion::setToRotateAboutZ(float theta)
{
	float thetaOver2 = theta * 0.5f;

	w = cos(thetaOver2);
	x = 0.0f;
	y = 0.0f;
	z = sin(thetaOver2);
}

void Quaternion::setToRotateAboutAxis(const Vector3& axis, float theta)
{
	assert(fabs(vectorMag(axis) - 1.0f) < 0.01f);

	float thetaOver2 = theta * 0.5f;
	float sinThetaOver2 = sin(thetaOver2);

	w = cos(thetaOver2);
	x = axis.x * sinThetaOver2;
	y = axis.y * sinThetaOver2;
	z = axis.z * sinThetaOver2;
}

float Quaternion::getRotationAngle() const
{
	float thetaOver2 = safeAcos(w);
	return thetaOver2 * 2.0f;
}

Vector3 Quaternion::getRotationAxis() const
{
	float sinThetaOver2Sq = 1.0f - w * w;

	float oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);

	return Vector3(x * oneOverSinThetaOver2, y * oneOverSinThetaOver2, z * oneOverSinThetaOver2);
}

Quaternion Quaternion::operator*(const Quaternion& a) const
{
	Quaternion result;
	result.w = w * a.w - x * a.x - y * a.y - z * a.z;
	result.x = w * a.x + x * a.w + z * a.y - y * a.z;
	result.y = w * a.y + y * a.w + x * a.z - z * a.x;
	result.z = w * a.z + z * a.w + y * a.x - x * a.y;
	return result;
}

Quaternion& Quaternion::operator*=(const Quaternion& a)
{
	*this = *this * a;
	return *this;
}

void Quaternion::normalize()
{
	float mag = (float)sqrt(w * w + x * x + y * y + z * z);

	if (mag > 0.0f)
	{
		float oneOverMag = 1.0f / mag;
		w *= oneOverMag;
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
	else
	{
		assert(false);
		identity();
	}
}

void Quaternion::fromRotationMatrix(const RotationMatrix& m)
{
	float m11 = m.m11;
	float m12 = m.m12;
	float m13 = m.m13;

	float m21 = m.m21;
	float m22 = m.m22;
	float m23 = m.m23;

	float m31 = m.m31;
	float m32 = m.m32;
	float m33 = m.m33;

	float fourWSquaredMinusl = m11 + m22 + m33;
	float fourXSquaredMinusl = m11 - m22 - m33;
	float fourYSquaredMinusl = -m11 + m22 - m33;
	float fourZSquaredMinusl = -m11 - m22 + m33;

	int biggestIndex = 0;
	float fourBiggestSquaredMinusl1 = fourWSquaredMinusl;
	if (fourXSquaredMinusl > fourBiggestSquaredMinusl1)
	{
		fourBiggestSquaredMinusl1 = fourXSquaredMinusl;
		biggestIndex = 1;
	}
	if (fourYSquaredMinusl > fourBiggestSquaredMinusl1)
	{
		fourBiggestSquaredMinusl1 = fourYSquaredMinusl;
		biggestIndex = 2;
	}
	if (fourZSquaredMinusl > fourBiggestSquaredMinusl1)
	{
		fourBiggestSquaredMinusl1 = fourZSquaredMinusl;
		biggestIndex = 3;
	}

	float biggestVal = sqrt(fourBiggestSquaredMinusl1 + 1.0f) * 0.5f;
	float mult = 0.25 / biggestVal;

	switch (biggestIndex)
	{
	case 0:
		w = biggestVal;
		x = (m23 - m32) * mult;
		y = (m31 - m13) * mult;
		z = (m12 - m21) * mult;
		break;
	case 1:
		x = biggestVal;
		w = (m23 - m32) * mult;
		y = (m12 + m21) * mult;
		z = (m31 + m13) * mult;
		break;
	case 2:
		y = biggestVal;
		w = (m31 - m13) * mult;
		x = (m12 + m21) * mult;
		z = (m23 + m32) * mult;
		break;
	case 3:
		z = biggestVal;
		w = (m12 - m21) * mult;
		x = (m31 + m13) * mult;
		y = (m23 + m32) * mult;
		break;
	default:
		break;
	}
}

void Quaternion::setToRotateObjectToInertial(const EulerAngles& orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch * 0.5f);
	sinCos(&sb, &cb, orientation.bank * 0.5f);
	sinCos(&sh, &ch, orientation.heading * 0.5f);

	w = ch * cp * cb + sh * sp * sb;
	x = ch * sp * cb + sh * cp * sb;
	y = sh * cp * cb - ch * sp * sb;
	z = ch * cp * sb - sh * sp * cb;
}

void Quaternion::setToRotateInertialToObject(const EulerAngles& orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch * 0.5f);
	sinCos(&sb, &cb, orientation.bank * 0.5f);
	sinCos(&sh, &ch, orientation.heading * 0.5f);

	w = ch * cp * cb + sh * sp * sb;
	x = -ch * sp * cb - sh * cp * sb;
	y = ch * sp * sb - sh * cp * cb;
	z = sh * sp * cb - ch * cp * sb;
}

float dotProduct(const Quaternion& a, const Quaternion& b)
{
	return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

Quaternion conjugate(const Quaternion& q)
{
	Quaternion result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}

Quaternion pow(const Quaternion& q, float exponent)
{
	if (fabs(q.w) > 0.9999f)
	{
		return q;
	}

	float alpha = acos(q.w);

	float newAlpha = exponent * alpha;

	Quaternion result;
	result.w = cos(newAlpha);

	float mult = sin(newAlpha) / sin(alpha);
	result.x = q.x * mult;
	result.y = q.y * mult;
	result.z = q.z * mult;

	return result;
}
