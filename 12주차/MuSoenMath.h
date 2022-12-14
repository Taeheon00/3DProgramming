#include <iostream>
#include <cmath>

#define PI 3.1415926 //sin cos���� ���� ���̰�
using namespace std;

class Mat3 {
public:
    float Mat[3][3]; // 2�������

    Mat3() { //  ��� ������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // ��� ���� �ʱ�ȭ
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
    }//����� ���� �Է¹޴� ������

    Mat3 identity_matrix()
    {
        return Mat3(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1);
    }//������ĸ� ��ȯ�ϴ� �Լ�

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
    }//��ġ��ķ� ��ȯ�ϴ� �Լ�
};

class Vec3 {
public:
    float x, y, z;
    float Mat[3][1];

    Vec3()
    {
        x = Mat[0][0] = 0;
        y = Mat[1][0] = 0;
        z = Mat[2][0] = 1;
    }//���� �Է¹��� �ʾ������� ����

    Vec3(float X, float Y, float Z)
    {
        x = Mat[0][0] = X;
        y = Mat[1][0] = Y;
        z = Mat[2][0] = Z;
    }//���� �Է¹޾Ƽ� ������ ����
};

class Vec1X3 {
public:
    float x, y, z;

    Vec1X3()
    {
        x = 0;
        y = 0;
        z = 1;
    }//���� �Է¹��� �ʾ������� ����

    Vec1X3(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }//���� �Է¹޾Ƽ� ������ ����
};

const Vec3 operator * (const Mat3 ref, const Vec3 vec) //vec3�� 3*3����� ������ ����
{
    Vec3 result;
    Mat3 mat = ref;
    mat = mat.transpose_matrix(); //��ġ��ķ� ��ȯ

    float x = vec.x; // 3*1����� x����
    float y = vec.y; // 3*1����� y����
    float z = vec.z;
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]);
    return result;
}

const Vec3 operator * (const Vec3 vec, const Mat3 ref) //vec3�� 3*3����� ������ ����
{
    Vec3 result;
    Mat3 mat = ref;
    mat = mat.transpose_matrix(); //��ġ��ķ� ��ȯ

    float x = vec.x; // 3*1����� x����
    float y = vec.y; // 3*1����� y����
    float z = vec.z;
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]);
    return result;
}

const Mat3 operator * (const Mat3 mat, const Mat3 ref) //3*3��� ������ ������ ����
{
    Mat3 result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] * ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X3 operator * (Vec1X3 vec, Vec1X3 ref) //1*3���� ������ ������ ����
{
    Vec1X3 result;
    result.x = vec.x * ref.x;
    result.y = vec.y * ref.y;
    result.z = vec.z * ref.z;
    return result;
}

const Vec3 operator * (Vec3 vec, Vec3 ref) //3*1���� ������ ������ ����
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

const Vec1X3 operator * (Vec1X3 vec, int ref) //1*3���Ϳ� ����� ������ ����
{
    Vec1X3 result;
    result.x = vec.x * ref;
    result.y = vec.y * ref;
    result.z = vec.z * ref;
    return result;
}

const Vec3 operator * (Vec3 vec, int ref) //3*1���Ϳ� ����� ������ ����
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] * ref;
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

const Mat3 operator / (Mat3 mat, Mat3 ref) //3*3��� ������ �������� ����
{
    Mat3 result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] / ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X3 operator / (Vec1X3 vec, Vec1X3 ref) //1*3���� ������ �������� ����
{
    Vec1X3 result;
    result.x = vec.x / ref.x;
    result.y = vec.y / ref.y;
    result.z = vec.z / ref.z;
    return result;
}

const Vec3 operator / (Vec3 vec, Vec3 ref) //3*1���� ������ �������� ����
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

const Vec1X3 operator / (Vec1X3 vec, int ref) //1*3���Ϳ� ����� �������� ����
{
    Vec1X3 result;
    result.x = vec.x / ref;
    result.y = vec.y / ref;
    result.z = vec.z / ref;
    return result;
}

const Vec3 operator / (Vec3 vec, int ref) //3*1���Ϳ� ����� �������� ����
{
    Vec3 result;
    for (int i = 0; i < 3; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] / ref;
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    return result;
}

const Mat3 operator + (const Mat3& mat, const Mat3& ref) //3*3��� ������ ������ ����
{
    Mat3 result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] + ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X3 operator + (Vec1X3 vec, Vec1X3 ref) //1*3���� ������ ������ ����
{
    Vec1X3 result;
    result.x = vec.x + ref.x;
    result.y = vec.y + ref.y;
    result.z = vec.z + ref.z;
    return result;
}

const Vec3 operator + (Vec3 vec, Vec3 ref) //3*1���� ������ ������ ����
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

const Mat3 operator - (const Mat3& mat, const Mat3& ref) //3*3��� ������ ������ ����
{
    Mat3 result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] - ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X3 operator - (Vec1X3 vec, Vec1X3 ref) //1*3���� ������ ������ ����
{
    Vec1X3 result;
    result.x = vec.x - ref.x;
    result.y = vec.y - ref.y;
    result.z = vec.z - ref.z;
    return result;
}

const Vec3 operator - (Vec3 vec, Vec3 ref) //3*1���� ������ ������ ����
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
    float Mat[4][4]; // 3�������

    Mat4() { //  ��� ������
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                Mat[i][j] = 0; // ��� ���� �ʱ�ȭ
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
    }//����� ���� �Է¹޴� ������

    Mat4 identity_matrix()
    {
        return Mat4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }//������ĸ� ��ȯ�ϴ� �Լ�

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
    }//��ġ��ķ� ��ȯ�ϴ� �Լ�
};

class Vec4 {
public:
    float x, y, z, w;
    float Mat[4][1];

    Vec4()
    {
        x = Mat[0][0] = 0;
        y = Mat[1][0] = 0;
        z = Mat[2][0] = 0;
        w = Mat[3][0] = 1;
    }//���� �Է¹��� �ʾ������� ����

    Vec4(float X, float Y, float Z, float W)
    {
        x = Mat[0][0] = X;
        y = Mat[1][0] = Y;
        z = Mat[2][0] = Z;
        w = Mat[3][0] = W;
    }//���� �Է¹޾Ƽ� ������ ����
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
    }//���� �Է¹��� �ʾ������� ����

    Vec1X4(float X, float Y, float Z, float W)
    {
        x = X;
        y = Y;
        z = Z;
        w = W;
    }//���� �Է¹޾Ƽ� ������ ����
};

const Vec4 operator * (Mat4 ref, Vec4 vec) //vec4�� 4*4����� ������ ����
{
    Vec4 result;
    Mat4 mat = ref;
    mat = mat.transpose_matrix(); //��ġ��ķ� ��ȯ

    float x = vec.x; // 4*1����� x����
    float y = vec.y; // 4*1����� y����
    float z = vec.z; // 4*1����� z����
    float w = vec.w; // 4*1����� w����
    result.x = (x * mat.Mat[0][0]) + (y * mat.Mat[0][1]) + (z * mat.Mat[0][2]) + (w * mat.Mat[0][3]);
    result.y = (x * mat.Mat[1][0]) + (y * mat.Mat[1][1]) + (z * mat.Mat[1][2]) + (w * mat.Mat[1][3]);
    result.z = (x * mat.Mat[2][0]) + (y * mat.Mat[2][1]) + (z * mat.Mat[2][2]) + (w * mat.Mat[2][3]);
    result.w = (x * mat.Mat[3][0]) + (y * mat.Mat[3][1]) + (z * mat.Mat[3][2]) + (w * mat.Mat[3][3]);
    return result;
}

const Vec4 operator * (Vec4 vec, Mat4 ref) //vec4�� 4*4����� ������ ����
{
    Vec4 result;

    float x = vec.x; // 4*1����� x����
    float y = vec.y; // 4*1����� y����
    float z = vec.z; // 4*1����� z����
    float w = vec.w; // 4*1����� w����
    result.x = (x * ref.Mat[0][0]) + (y * ref.Mat[1][0]) + (z * ref.Mat[2][0]) + (w * ref.Mat[3][0]);
    result.y = (x * ref.Mat[0][1]) + (y * ref.Mat[1][1]) + (z * ref.Mat[2][1]) + (w * ref.Mat[3][1]);
    result.z = (x * ref.Mat[0][2]) + (y * ref.Mat[1][2]) + (z * ref.Mat[2][2]) + (w * ref.Mat[3][2]);
    result.w = (x * ref.Mat[0][3]) + (y * ref.Mat[1][3]) + (z * ref.Mat[2][3]) + (w * ref.Mat[3][3]);
    return result;
}

const Mat4 operator * (Mat4 mat, Mat4 ref) //4*4��� ������ ������ ����
{
    Mat4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] * ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X4 operator * (Vec1X4 vec, Vec1X4 ref) //1*4���� ������ ������ ����
{
    Vec1X4 result;
    result.x = vec.x * ref.x;
    result.y = vec.y * ref.y;
    result.z = vec.z * ref.z;
    result.w = vec.w * ref.w;
    return result;
}

const Vec4 operator * (Vec4 vec, Vec4 ref) //4*1���� ������ ������ ����
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

const Vec1X4 operator * (Vec1X4 vec, int ref) //1*4���Ϳ� ����� ������ ����
{
    Vec1X4 result;
    result.x = vec.x * ref;
    result.y = vec.y * ref;
    result.z = vec.z * ref;
    result.w = vec.w * ref;
    return result;
}

const Vec4 operator * (Vec4 vec, int ref) //4*1���Ϳ� ����� ������ ����
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] * ref;
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}

const Mat4 operator / (Mat4 mat, Mat4 ref) //4*4��� ������ �������� ����
{
    Mat4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] / ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X4 operator / (Vec1X4 vec, Vec1X4 ref) //1*4���� ������ �������� ����
{
    Vec1X4 result;
    result.x = vec.x / ref.x;
    result.y = vec.y / ref.y;
    result.z = vec.z / ref.z;
    result.w = vec.w / ref.w;
    return result;
}

const Vec4 operator / (Vec4 vec, Vec4 ref) //4*1���� ������ �������� ����
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

const Vec1X4 operator / (Vec1X4 vec, int ref) //1*4���Ϳ� ����� �������� ����
{
    Vec1X4 result;
    result.x = vec.x / ref;
    result.y = vec.y / ref;
    result.z = vec.z / ref;
    result.w = vec.w / ref;
    return result;
}

const Vec4 operator / (Vec4 vec, int ref) //4*1���Ϳ� ����� �������� ����
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
    {
        result.Mat[i][0] = vec.Mat[i][0] / ref;
    }
    result.x = result.Mat[0][0];
    result.y = result.Mat[1][0];
    result.z = result.Mat[2][0];
    result.w = result.Mat[3][0];
    return result;
}

const Mat4 operator + (Mat4 mat, Mat4 ref) //4*4��� ������ ������ ����
{
    Mat4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] + ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X4 operator + (Vec1X4 vec, Vec1X4 ref) //1*4���� �����ǵ����� ����
{
    Vec1X4 result;
    result.x = vec.x + ref.x;
    result.y = vec.y + ref.y;
    result.z = vec.z + ref.z;
    result.w = vec.w + ref.w;
    return result;
}

const Vec4 operator + (Vec4 vec, Vec4 ref) //4*1���� �����ǵ����� ����
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

const Mat4 operator - (Mat4 mat, Mat4 ref) //4*4��� ������ ������ ����
{
    Mat4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result.Mat[i][j] += mat.Mat[i][k] - ref.Mat[k][j];
            }
        }
    }

    return result;
}

const Vec1X4 operator - (Vec1X4 vec, Vec1X4 ref) //1*4���� ������ ������ ����
{
    Vec1X4 result;
    result.x = vec.x - ref.x;
    result.y = vec.y - ref.y;
    result.z = vec.z - ref.z;
    result.w = vec.w - ref.w;
    return result;
}

const Vec4 operator - (Vec4 vec, Vec4 ref) //4*1���� ������ ������ ����
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