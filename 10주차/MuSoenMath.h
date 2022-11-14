#include <iostream>
#include <cmath>

#define PI 3.1415926 //sin cos값을 위한 파이값
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
    
    Mat3(float _00, float _01, float _02,
        float _10, float _11, float _12,
        float _20, float _21, float _22)
    {
        Mat[0][0] = _00;
        Mat[0][1] = _01;
        Mat[0][2] = _02;
        Mat[1][0] = _10;
        Mat[1][1] = _11;
        Mat[1][2] = _12;
        Mat[2][0] = _20;
        Mat[2][1] = _21;
        Mat[2][2] = _22;
    }//행렬의 값을 입력받는 생성자

    Mat3 identity_matrix()
    {
        return Mat3(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1);
    }//단위행렬를 반환하는 함수

    Mat3 transpose_matrix()
    {
        Mat3 result;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.Mat[i][j] = Mat[j][i];
            }
        }

        return result;
    }//전치행렬로 변환하는 함수

    Mat3 multiply_matrix()
    {
       
    }

    Mat3 multiply_transpose_matrix()
    {

    }
};

class Vec3 { 
public:
    float x, y,z;
    float Mat[3][1];

    Vec3()
    {
        x = Mat[0][0] = 0;
        y = Mat[1][0] = 0;
        z = Mat[2][0] = 1;
    }//값을 입력받지 않았을때의 원점

    Vec3(float X, float Y, float Z)
    {
        x = Mat[0][0] = X;
        y = Mat[1][0] = Y;
        z = Mat[2][0] = Z;
    }//값을 입력받아서 원점을 설정

    Vec3 multiply_vector()
    {

    }

    Vec3 multiply_transpose_vector()
    {

    }
};

class Vec1X3 {
public:
    float x, y, z;

    Vec1X3()
    {
        x = 0;
        y = 0;
        z = 1;
    }//값을 입력받지 않았을때의 원점

    Vec1X3(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }//값을 입력받아서 원점을 설정

    Vec1X3 multiply_vector()
    {

    }

    Vec1X3 multiply_transpose_vector()
    {

    }
};

const Vec3 operator * (const Mat3& ref, const Vec3& vec) //vec3와 3*3행렬의 곱셈을 구현
{
    Vec3 result;
    Mat3 mat = ref;
    mat = mat.transpose_matrix(); //전치행렬로 변환

    float x = vec.x; // 3*1행렬의 x설정
    float y = vec.y; // 3*1행렬의 y설정
    float z = vec.z;
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]);
    return result;
}

const Vec3 operator * (const Vec3& vec, const Mat3& ref) //vec3와 3*3행렬의 곱셈을 구현
{
    Vec3 result;
    Mat3 mat = ref;
    mat = mat.transpose_matrix(); //전치행렬로 변환

    float x = vec.x; // 3*1행렬의 x설정
    float y = vec.y; // 3*1행렬의 y설정
    float z = vec.z; // 3*1행렬의 z설정
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]); 
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]);
    return result;
}

const Mat3 operator * (const Mat3& mat, const Mat3& ref) //3*3행렬 끼리의 곱셈을 구현
{
    Mat3 result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] * ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X3 operator * (Vec1X3 vec, Vec1X3 ref) //1*3벡터 끼리의 곱셈을 구현
{
    Vec1X3 result;
    result.x = vec.x * ref.x;
    result.y = vec.y * ref.y;
    result.z = vec.z * ref.z;
    return result;
}

const Vec3 operator * (Vec3 vec, Vec3 ref) //3*1벡터 끼리의 곱셈을 구현
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] * ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

const Mat3 operator / (const Mat3& mat, const Mat3& ref) //3*3행렬 끼리의 나눗셈을 구현
{
    Mat3 result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] / ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X3 operator / (Vec1X3 vec, Vec1X3 ref) //1*3벡터 끼리의 나눗셈을 구현
{
    Vec1X3 result;
    result.x = vec.x / ref.x;
    result.y = vec.y / ref.y;
    result.z = vec.z / ref.z;
    return result;
}

const Vec3 operator / (Vec3 vec, Vec3 ref) //3*1벡터 끼리의 나눗셈을 구현
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] / ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

const Mat3 operator + (const Mat3& mat, const Mat3& ref) //3*3행렬 끼리의 덧셈을 구현
{
    Mat3 result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
        {
            result.Mat[i][j] = mat.Mat[i][j] + ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X3 operator + (Vec1X3 vec, Vec1X3 ref) //1*3벡터 끼리의 덧셈을 구현
{
    Vec1X3 result;
    result.x = vec.x + ref.x;
    result.y = vec.y + ref.y;
    result.z = vec.z + ref.z;
    return result;
}

const Vec3 operator + (Vec3 vec, Vec3 ref) //3*1벡터 끼리의 덧셈을 구현
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] + ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

const Mat3 operator - (const Mat3& mat, const Mat3& ref) //3*3행렬 끼리의 뺄셈을 구현
{
    Mat3 result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] - ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X3 operator - (Vec1X3 vec, Vec1X3 ref) //1*3벡터 끼리의 뺄셈을 구현
{
    Vec1X3 result;
    result.x = vec.x - ref.x;
    result.y = vec.y - ref.y;
    result.z = vec.z - ref.z;
    return result;
}

const Vec3 operator - (Vec3 vec, Vec3 ref) //3*1벡터 끼리의 뺄셈을 구현
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] - ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

class Mat4 {
public:
    float Mat[4][4]; // 3차원행렬

    Mat4() { //  행렬 생성자
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                Mat[i][j] = 0; // 멤버 변수 초기화
            }
        }
    }

    Mat4(float _00, float _01, float _02, float _03,
        float _10, float _11, float _12, float _13,
        float _20, float _21, float _22, float _23,
        float _30, float _31, float _32, float _33)
    {
        Mat[0][0] = _00;
        Mat[0][1] = _01;
        Mat[0][2] = _02;
        Mat[0][3] = _03;
        Mat[1][0] = _10;
        Mat[1][1] = _11;
        Mat[1][2] = _12;
        Mat[1][3] = _13;
        Mat[2][0] = _20;
        Mat[2][1] = _21;
        Mat[2][2] = _22;
        Mat[2][3] = _23;
        Mat[3][0] = _30;
        Mat[3][1] = _31;
        Mat[3][2] = _32;
        Mat[3][3] = _33;
    }//행렬의 값을 입력받는 생성자

    Mat4 identity_matrix()
    {
        return Mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }//단위행렬를 반환하는 함수

    Mat4 transpose_matrix()
    {
        Mat4 result;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result.Mat[i][j] = Mat[j][i];
            }
        }

        return result;
    }//전치행렬로 변환하는 함수

    Mat4 multiply_matrix()
    {

    }

    Mat4 multiply_transpose_matrix()
    {

    }
};

class Vec4 {
public:
    float x, y, z,w;
    float Mat[4][1];

    Vec4()
    {
        x = Mat[0][0] = 0;
        y = Mat[1][0] = 0;
        z = Mat[2][0] = 0;
        w = Mat[3][0] = 1;
    }//값을 입력받지 않았을때의 원점

    Vec4(float X, float Y, float Z, float W)
    {
        x = Mat[0][0] = X;
        y = Mat[1][0] = Y;
        z = Mat[2][0] = Z;
        w = Mat[3][0] = W;
    }//값을 입력받아서 원점을 설정

    Vec4 multiply_vector()
    {

    }

    Vec4 multiply_transpose_vector()
    {

    }
};

class Vec1X4 {
public:
    float x, y, z, w;

    Vec1X4()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 1;
    }//값을 입력받지 않았을때의 원점

    Vec1X4(float X, float Y, float Z, float W)
    {
        x = X;
        y = Y;
        z = Z;
        w = W;
    }//값을 입력받아서 원점을 설정

    Vec4 multiply_vector()
    {

    }

    Vec4 multiply_transpose_vector()
    {

    }
};

const Vec4 operator * ( Mat4 ref,  Vec4 vec) //vec4와 4*4행렬의 곱셈을 구현
{
    Vec4 result;
    Mat4 mat = ref;
    mat = mat.transpose_matrix(); //전치행렬로 변환

    float x = vec.x; // 4*1행렬의 x설정
    float y = vec.y; // 4*1행렬의 y설정
    float z = vec.z; // 4*1행렬의 z설정
    float w = vec.w; // 4*1행렬의 w설정
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]) + (w * mat.Mat[0][3]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]) + (w * mat.Mat[1][3]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]) + (w * mat.Mat[2][3]);
    result.w = (x * mat.Mat[3][0]) + (y * mat.Mat[3][1]) + (z * mat.Mat[3][2]) + (w * mat.Mat[3][3]);
    return result;
}

const Vec4 operator * ( Vec4 vec,  Mat4 ref) //vec4와 4*4행렬의 곱셈을 구현
{
    Vec4 result;
    Mat4 mat = ref;
    mat = mat.transpose_matrix(); //전치행렬로 변환

    float x = vec.x; // 4*1행렬의 x설정
    float y = vec.y; // 4*1행렬의 y설정
    float z = vec.z; // 4*1행렬의 z설정
    float w = vec.w; // 4*1행렬의 w설정
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]) + (w * mat.Mat[0][3]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]) + (w * mat.Mat[1][3]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]) + (w * mat.Mat[2][3]);
    result.w = (x * mat.Mat[3][0]) + (y * mat.Mat[3][1]) + (z * mat.Mat[3][2]) + (w * mat.Mat[3][3]);
    return result;
}

const Mat4 operator * ( Mat4 mat, Mat4 ref) //4*4행렬 끼리의 곱셈을 구현
{
    Mat4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] * ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X4 operator * (Vec1X4 vec, Vec1X4 ref) //1*4벡터 끼리의 곱셈을 구현
{
    Vec1X4 result;
    result.x = vec.x * ref.x;
    result.y = vec.y * ref.y;
    result.z = vec.z * ref.z;
    result.w = vec.w * ref.w;
    return result;
}

const Vec4 operator * (Vec4 vec, Vec4 ref) //4*1벡터 끼리의 곱셈을 구현
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] * ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}

const Mat4 operator / (Mat4 mat, Mat4 ref) //4*4행렬 끼리의 나눗셈을 구현
{
    Mat4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] / ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X4 operator / (Vec1X4 vec, Vec1X4 ref) //1*4벡터 끼리의 나눗셈을 구현
{
    Vec1X4 result;
    result.x = vec.x / ref.x;
    result.y = vec.y / ref.y;
    result.z = vec.z / ref.z;
    result.w = vec.w / ref.w;
    return result;
}

const Vec4 operator / (Vec4 vec, Vec4 ref) //4*1벡터 끼리의 나눗셈을 구현
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] / ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}

const Mat4 operator + (Mat4 mat, Mat4 ref) //4*4행렬 끼리의 덧셈을 구현
{
    Mat4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] + ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X4 operator + (Vec1X4 vec, Vec1X4 ref) //1*4벡터 끼리의덧셈을 구현
{
    Vec1X4 result;
    result.x = vec.x + ref.x;
    result.y = vec.y + ref.y;
    result.z = vec.z + ref.z;
    result.w = vec.w + ref.w;
    return result;
}

const Vec4 operator + (Vec4 vec, Vec4 ref) //4*1벡터 끼리의덧셈을 구현
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] + ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}

const Mat4 operator - (Mat4 mat, Mat4 ref) //4*4행렬 끼리의 뺄셈을 구현
{
    Mat4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            result.Mat[i][j] = mat.Mat[i][j] - ref.Mat[i][j];
        }
    }

    return result;
}

const Vec1X4 operator - (Vec1X4 vec, Vec1X4 ref) //1*4벡터 끼리의 뺄셈을 구현
{
    Vec1X4 result;
    result.x = vec.x - ref.x;
    result.y = vec.y - ref.y;
    result.z = vec.z - ref.z;
    result.w = vec.w - ref.w;
    return result;
}

const Vec4 operator - (Vec4 vec, Vec4 ref) //4*1벡터 끼리의 뺄셈을 구현
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] - ref.Mat[i][0];
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}