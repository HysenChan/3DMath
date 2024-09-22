#include<iostream>
#include"Vector3.h"

using namespace std;

void print_v(Vector3 v)
{
	cout << "[" << v.x << "," << v.y << "," << v.z << "]";
}

int main()
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

	system("pause");
	return 0;
}