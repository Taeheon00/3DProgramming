#include "MuSoenMath.h"

void main()
{
	Vec4 v;

	Mat4 Translate = Mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 1, 1); //이동행렬 입력

	Mat4 Rotate = Mat4(
		cos(30 * PI / 180), -sin(30 * PI / 180), 0, 0,
		sin(30 * PI / 180), cos(30 * PI / 180), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);//회전행렬 입력

	Mat4 Scale = Mat4(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1);//크기 행렬 입력

	Vec4 p = v * Translate * Rotate * Scale;

	Mat3 a = Mat3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);

	Mat3 b = Mat3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);

	Mat3 c = a * b;

	Vec4 w = Vec4(1, 2, 3, 4);
	Vec4 e = Vec4(1, 2, 3, 4);

	Vec4 r = w + e;

	cout << fixed;
	cout.precision(0); // 소수점 제거

	cout << "원점이 0,0,0일때 3,5이동 30도회전 2배확대했을때의 좌표값은: " << endl;
	cout << p.x << "," << p.y << "," << p.z << "입니다." << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << c.Mat[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}

	cout << r.x << endl;
	cout << r.y << endl;
	cout << r.z << endl;
	cout << r.w << endl;
}