#include"EulerAngles.h"
#include"MathUtil.h"

//heading	-180° ~ +180°
//bank		-180° ~ +180°
//pitch		-90° ~ +90°
void EulerAngles::canonize()
{
	pitch = wrapPi(pitch);

	if (pitch < -kPiOver2)
	{
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	else if (pitch > kPiOver2)
	{
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}

	if (fabs(pitch) > kPiOver2 - 1e-4)
	{
		heading += bank;
		bank = 0.0f;
	}
	else
	{
		bank = wrapPi(bank);
	}

	heading = wrapPi(heading);
}

void EulerAngles::fromObjectToWorldMatrix(const Matrix4x3& m)
{
	float sp = -m.m23;

	//检测万向锁
	if (fabs(sp) > 0.99999f)
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m31, m.m11);
	}
	else
	{
		heading = atan2(m.m13, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m21, m.m22);
	}
}

void EulerAngles::fromWorldToObjectMatrix(const Matrix4x3& m)
{
	float sp = -m.m32;

	//检测万向锁
	if (fabs(sp) > 0.99999f)
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m13, m.m11);
	}
	else
	{
		heading = atan2(m.m31, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m12, m.m22);
	}
}

void EulerAngles::fromRotationMatrix(const RotationMatrix& m)
{
	float sp = -m.m32;

	//检测万向锁
	if (fabs(sp) > 0.99999f)
	{
		pitch = kPiOver2 * sp;
		bank = 0.0f;
		heading = atan2(-m.m31, m.m11);
	}
	else
	{
		heading = atan2(m.m31, m.m33);
		pitch = asin(sp);
		bank = atan2(m.m12, m.m22);
	}
}
