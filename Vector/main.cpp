#include<iostream>
#include"Vector3.h"
#include"Matrix4x3.h"
#include"MathUtil.h"
#include"RotationMatrix.h"
#include"EulerAngles.h"

using namespace std;

int classifySpherePlane(
	const Vector3& planeNormal,
	float planeD,
	const Vector3& sphereCenter,
	float sphereRadius)
{
	float d = planeNormal * sphereCenter - planeD;

	if (d >= sphereRadius)
	{
		return 1;
	}
	if (d <= -sphereRadius)
	{
		return -1;
	}
	return 0;//相交
}

bool isConvex(int n, const Vector3 v1[])
{
	float angleSum = 0.0f;

	for (int i = 0; i < n; ++i)
	{
		Vector3 e1;
		if (i == 0)
		{
			e1 = v1[n - 1] - v1[i];
		}
		else
		{
			e1 = v1[i - 1] - v1[i];
		}

		Vector3 e2;
		if (i == n - 1)
		{
			e2 = v1[0] - v1[i];
		}
		else
		{
			e2 = v1[i + 1] - v1[i];
		}

		e1.normalize();
		e2.normalize();
		float dot = e1 * e2;
		float theta = safeAcos(dot);
		angleSum += theta;

	}
	float convexAngleSum = (float)(n - 2) * kPi;
	if (angleSum < convexAngleSum - (float)n * 0.0001f)
	{
		return false;
	}
	return true;
}

class Line3D
{
public:
	Vector3 origin;//线段的起点
	Vector3 end;//线段的终点
};

class Ray3D
{
public:
	Vector3 rayOrigin;//射线的起点
	Vector3 rayDelta;//射线的增量
};

class Sphere
{
public:
	Vector3 center;//球心
	float radius;//半径
};

float to_zero(float n)
{
	return ((abs(n) < 0.00001) ? 0 : n);
}

void print_v(Vector3 v)
{
	cout << "[" << to_zero(v.x)
		<< "," << to_zero(v.y)
		<< "," << to_zero(v.z) << "]" << endl;
}


void Vector()
{
	cout << "hello vector" << endl;
	Vector3 v1(10, 20, 30);
	print_v(v1);

	Vector3 v2(v1);
	print_v(v2);

	Vector3 v3 = -v1;
	print_v(v3);

	v2.zero();
	print_v(v2);

	Vector3 v4(5, -4, 7);
	float r = vectorMag(v4);
	cout << r << endl;

	Vector3 v5(-5, 0, 0.4);
	Vector3 v6 = v5 * -5;
	print_v(v6);

	v5 *= -3;
	print_v(v5);

	Vector3 v7(4.7, -6, 8);
	Vector3 v8 = v7 / 2;
	print_v(v8);

	Vector3 v9(1, 2, 3);
	Vector3 v10 = 2 * v9;
	print_v(v10);

	Vector3 v11(12, -5, 0);
	v11.normalize();
	print_v(v11);

	Vector3 a(1, 2, 3);
	Vector3 b(4, 5, 6);
	Vector3 r1 = a + b;
	print_v(r1);

	Vector3 r2 = b - a;
	print_v(r2);

	Vector3 x(5, 0, 0);
	Vector3 y(-1, 8, 0);
	float d = distance(x, y);
	cout << d << endl;

	Vector3 h1(3, -2, 7);
	Vector3 h2(0, 4, -1);
	float dot = h1 * h2;
	cout << dot << endl;

	double arc = acos(dot / (vectorMag(h1) * vectorMag(h2))) * 180 / 3.1415;
	cout << arc << endl;

	Vector3 t1(1, 3, 4);
	Vector3 t2(2, -5, 8);
	Vector3 t3 = crossProduct(t1, t2);
	print_v(t3);
}

void print_m(Matrix4x3 m)
{
	cout << to_zero(m.m11) << "\t" << to_zero(m.m12) << "\t" << to_zero(m.m13) << endl;
	cout << to_zero(m.m21) << "\t" << to_zero(m.m22) << "\t" << to_zero(m.m23) << endl;
	cout << to_zero(m.m31) << "\t" << to_zero(m.m32) << "\t" << to_zero(m.m33) << endl;
}

void Matrix()
{
	cout << "hello matrix" << endl;
	Matrix4x3 a, b, c;
	a.m11 = 1, a.m12 = -5, a.m13 = 3;
	a.m21 = 0, a.m22 = -2, a.m23 = 6;
	a.m31 = 7, a.m32 = 2, a.m33 = -4;

	b.m11 = -8, b.m12 = 6, b.m13 = 1;
	b.m21 = 7, b.m22 = 0, b.m23 = -3;
	b.m31 = 2, b.m32 = 4, b.m33 = 5;

	cout << "first calc matrix3x3 with matrix3x3" << endl;

	c = a * b;
	print_m(c);

	cout << "second calc matrix3x3 with matrix3x3" << endl;

	a *= b;
	print_m(a);

	Vector3 v(3, -1, 4);
	Matrix4x3 m;
	m.m11 = -2, m.m12 = 0, m.m13 = 3;
	m.m21 = 5, m.m22 = 7, m.m23 = -6;
	m.m31 = 1, m.m32 = -4, m.m33 = 2;

	cout << "first calc vector with matrix3x3" << endl;

	Vector3 r = v * m;
	print_v(r);

	/*cout << "second calc vector with matrix3x3" << endl;
	v = v * m;
	print_v(v);*/

	cout << "first calc matrix3x3 with vector" << endl;
	Vector3 r1 = m * v;
	print_v(r1);

	cout << "second calc matrix3x3 with vector" << endl;
	v = m * v;
	print_v(v);
}

void TransRotation()
{
	cout << "hello transrotation" << endl;

	Vector3 a(10, 0, 0), b;
	Matrix4x3 M;
	M.setRotate(3, kPiOver2);
	print_m(M);

	b = a * M;
	print_v(b);

	M.setRotate(3, kPi);
	print_m(M);
	b = a * M;
	print_v(b);

	M.setRotate(1, -22 * kPi / 180);
	print_m(M);

	M.setRotate(2, 30 * kPi / 180);
	print_m(M);
}

void TransScale()
{
	cout << "hello transscale" << endl;
	Vector3 a(10, 20, 30), b;
	print_v(a);

	Matrix4x3 M;
	Vector3 s(1, 2, 3);
	M.setupScale(s);
	print_m(M);
	b = a * M;
	print_v(b);
}

void TransProject()
{
	cout << "hello transproject" << endl;
	Vector3 a(10, 20, 30), b;
	print_v(a);

	Matrix4x3 M;

	Vector3 n(0, 0, 1);
	M.setupProject(n);
	print_m(M);
	b = a * M;
	print_v(b);
}

void TransRelfect()
{
	cout << "hello transreflect" << endl;

	Vector3 a(10, 20, 30), b;
	print_v(a);

	Matrix4x3 M;

	M.setupReflect(1, 1);
	b = a * M;
	print_v(b);

	M.setupReflect(2, 1);
	b = a * M;
	print_v(b);

	M.setupReflect(3, 1);
	b = a * M;
	print_v(b);

	Vector3 n(0, 0, 1);
	M.setupReflect(n);
	b = a * M;
	print_v(b);
}

void TransShear()
{
	cout << "hello transshear" << endl;

	Vector3 a(10, 20, 30), b;

	Matrix4x3 M;

	M.setupShear(1, 1, 2);//用x切边y和z(10,20+1*10=30,30+2*10=50)
	b = a * M;
	print_v(b);
}

void Determinant()
{
	cout << "hello Determinant" << endl;

	Matrix4x3 m;
	m.m11 = 3; m.m12 = -2; m.m13 = 0;
	m.m21 = 1; m.m22 = 4; m.m23 = -3;
	m.m31 = -1; m.m32 = 0; m.m33 = 2;

	float detM = determinant(m);
	cout << detM << endl;
}

void Inverse()
{
	cout << "hello Matrix Inverse" << endl;

	Matrix4x3 m;
	m.m11 = -4; m.m12 = -3; m.m13 = 3;
	m.m21 = 0; m.m22 = 2; m.m23 = -2;
	m.m31 = 1; m.m32 = 4; m.m33 = -1;

	Matrix4x3 r = inverse(m);
	print_m(r);

	Matrix4x3 a = m * r;//(矩阵)和(矩阵的逆)相乘得到单位矩阵。
	print_m(a);
}

void RotationMatrixFunc()
{
	cout << "旋转矩阵" << endl;

	RotationMatrix m;
	m.m11 = 0.866f; m.m12 = 0.0f; m.m13 = -0.5f;
	m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
	m.m31 = 0.5f; m.m32 = 0.0f; m.m33 = 0.866f;

	Vector3 v(10, 20, 30);
	Vector3 v2;
	v2 = m.inertialToObject(v);
	print_v(v2);
	v2 = m.objectToInertial(v);
	print_v(v2);
}

void print_e(EulerAngles e)
{
	//弧度转角度：弧度*180/PI
	//角度转弧度：角度*PI/180
	cout << "e.pitch(x):" << e.pitch * 180 / kPi << ",e.heading(y): " << e.heading * 180 / kPi << ", e.bank(z): " << e.bank * 180 / kPi << endl;
}

void EulerRotationFunc()
{
	cout << "欧拉角" << endl;

	/*RotationMatrix m;

	m.setup(EulerAngles(30 * kPi / 180, 0, 0));

	Vector3 v(10, 20, 30);
	Vector3 v2;
	v2 = m.inertialToObject(v);
	print_v(v2);
	v2 = m.objectToInertial(v);
	print_v(v2);*/

	EulerAngles ex, ey, ez;

	Matrix4x3 mx, my, mz;

	cout << "----------绕x轴--------" << endl;
	mx.m11 = 1.0f; mx.m12 = 0.0f; mx.m13 = 0.0f;//mx.m23和mx.m32符号对换
	mx.m21 = 0.0f; mx.m22 = 0.866f; mx.m23 = -0.5f;
	mx.m31 = 0.0f; mx.m32 = 0.5f; mx.m33 = 0.866f;
	print_m(mx);
	ex.fromObjectToWorldMatrix(mx);
	print_m(mx);
	print_e(ex);//(-30°,0,0)
	ex.fromWorldToObjectMatrix(mx);
	print_m(mx);
	print_e(ex);//(30°,0,0)
	cout << "----------绕x轴 end--------" << endl;
	cout << "----------绕y轴--------" << endl;
	my.m11 = 0.866f; my.m12 = 0.0f; my.m13 = -0.5f;
	my.m21 = 0.0f; my.m22 = 1.0f; my.m23 = 0.0f;
	my.m31 = 0.5f; my.m32 = 0.0f; my.m33 = 0.866f;
	print_m(my);
	ey.fromObjectToWorldMatrix(my);
	print_m(my);
	print_e(ey);//(0,30°,0)
	ey.fromWorldToObjectMatrix(my);
	print_m(my);
	print_e(ey);//(0,-30°,0)
	cout << "----------绕y轴 end--------" << endl;
	cout << "----------绕z轴--------" << endl;
	mz.m11 = 0.866f; mz.m12 = -0.5f; mz.m13 = 0.0f;//mz.m12和mz.m21符号对换
	mz.m21 = 0.5f; mz.m22 = 0.866f; mz.m23 = 0.0f;
	mz.m31 = 0.0f; mz.m32 = 0.0f; mz.m33 = 1.0f;
	print_m(mz);
	ez.fromObjectToWorldMatrix(mz);
	print_m(mz);
	print_e(ez);//(0,0,-30°)
	ez.fromWorldToObjectMatrix(mz);
	print_m(mz);
	print_e(ez);//(0,0,30°)
	cout << "----------绕z轴 end--------" << endl;

	EulerAngles eTest;

	Matrix4x3 mTest;
	cout << "----------绕test轴--------" << endl;
	mTest.m11 = 1.0f; mTest.m12 = 0.0f; mTest.m13 = 1.0f;
	mTest.m21 = 1.0f; mTest.m22 = 1.0f; mTest.m23 = 0.0f;
	mTest.m31 = 1.0f; mTest.m32 = 1.0f; mTest.m33 = 1.0f;
	print_m(mTest);
	eTest.fromObjectToWorldMatrix(mTest);
	print_m(mTest);
	print_e(eTest);//(0,0,-30°)
	eTest.fromWorldToObjectMatrix(mTest);
	print_m(mTest);
	print_e(eTest);//(0,0,30°)
	cout << "----------绕test轴 end--------" << endl;
}

//计算多于3个点的最佳法向量
Vector3 computeBestFixNormal(const Vector3 v[], int n)
{
	Vector3 result = kZeroVector;

	const Vector3* p = &v[n - 1];

	for (int i = 0; i < n; ++i)
	{
		const Vector3* c = &v[i];
		result.x += (p->z + c->z) * (p->y - c->y);
		result.y += (p->x + c->x) * (p->z - c->z);
		result.z += (p->y + c->y) * (p->x - c->x);

		p = c;
	}

	result.normalize();

	return result;
}

int main()
{
	//Vector();

	//Matrix();

	//线性变换 begin
	//TransRotation();
	//TransScale();
	//TransProject();
	//TransRelfect();
	//TransShear();
	//线性变换 end

	//行列式 begin
	//Determinant();//几何意义：2D的行列式-》面积  3D的行列式-》体积
	//Inverse();//做了线性变换之后想反悔，用矩阵的逆相乘，可以撤销。

	//行列式 end

	//旋转的三种表示方法
	//RotationMatrixFunc();//1.矩阵
	//EulerRotationFunc();//2.欧拉角

	//旋转的三种表示方法 end

	system("pause");
	return 0;
}