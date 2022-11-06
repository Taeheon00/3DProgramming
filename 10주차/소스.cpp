#include "MuSoenMath.h"

void main() {

	Vec3 Vector(0, 0); //원점을 0,0으로 기본백터 설정
	Mat3 Matrix;

	Matrix.Translate(3, 5); // 3,5로 이동
	Vector = Vector * Matrix; // 연산자 오버로딩으로 백터와 행렬 계산
	Matrix.Rotate(30); // 30도 회전
	Vector = Vector * Matrix;// 연산자 오버로딩으로 백터와 행렬 계산
	Matrix.Scale(2); // 크기를 2배로 확대
	Vector = Vector * Matrix;// 연산자 오버로딩으로 백터와 행렬 계산

	cout << fixed;
	cout.precision(0); // 소수점 제거

	cout << "원점이 0,0일때 3,5이동 30도회전 2배확대했을때의 좌표값은: "<<  endl;
	cout << Vector.Position[0] << "," << Vector.Position[1] << "입니다." << endl;
}
