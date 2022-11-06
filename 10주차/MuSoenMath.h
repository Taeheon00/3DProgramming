#include <iostream>
#include <cmath>

using namespace std;
class Mat3 { 
public:
    float Mat[3][3]; // 2차원행렬

    Mat3() { //  행렬 생성자
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // 멤버 변수 초기화
            }
        }
    }
    void Reset() { // 행렬 초기화 함수
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1; //2차원 좌표에서 z축은 존재하지 않음으로 1로 초기화
    }

    void Translate(float x, float y) 
    { 
        Reset();
        Mat[0][0] = 1;
        Mat[1][1] = 1;
        Mat[2][0] = x; 
        Mat[2][1] = y; 
        // 이동 변환 행렬 공식에 맞게 설정
    }

    void Rotate(float r) 
    {
        Reset();
        double Rotate = r * (3.14 / 180); // 라디안 설정
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate); 
        // 회전 변환 행렬 공식에 맞게 설정
    }

    void Scale(float s) 
    { 
        Reset();
        Mat[0][0] = s;
        Mat[1][1] = s; 
        // 크기 변환 행렬 공식에 맞게 설정
    }

};

class Vec3 { 
public:
    float Position[2]; // 2차원좌표+동차좌표

    Vec3(float x, float y) { // 생성자
        Position[0] = x;
        Position[1] = y;
    }

    Vec3 operator *(Mat3& p) // 연산자 오버로딩
    {
        float x = Position[0]; // 3*1행렬의 x설정
        float y = Position[1]; // 3*1행렬의 y설정
        float z = 1; // 3*1행렬의 z설정
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]); // 행렬곱 x좌표 결과값 저장
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]); // 행렬곱 y좌표 결과값 저장
        // Z좌표는 2차원에선 필요없으므로 생략
        return Vec3(a, b); // 저장된 x,y좌표 리턴
    }
};