#include<iostream>
#include"Vector3.h"
#include"Matrix4x3.h"
#include"MathUtil.h"
#include"RotationMatrix.h"
#include"EulerAngles.h"

using namespace std;

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
	cout << "e.heading:" << e.heading * 180 / kPi << ",e.pitch:" << e.pitch * 180 / kPi << ",e.bank:" << e.bank * 180 / kPi << endl;
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

	EulerAngles e;

	Matrix4x3 m;
	m.m11 = 0.866f; m.m12 = 0.0f; m.m13 = -0.5f;
	m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = 0.0f;
	m.m31 = 0.5f; m.m32 = 0.0f; m.m33 = 0.866f;

	print_m(m);
	e.fromObjectToWorldMatrix(m);
	print_m(m);
	print_e(e);//-30°
	e.fromWorldToObjectMatrix(m);
	print_m(m);
	print_e(e);//30°
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
	EulerRotationFunc();//2.欧拉角

	//旋转的三种表示方法 end

	system("pause");
	return 0;
}