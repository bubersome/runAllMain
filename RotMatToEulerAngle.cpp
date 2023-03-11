//
// Created by Ben X on 3/11/23.
//



#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

static void RotMatToEulerAngle(const float* _rotationM, float* _eulerAngles)
{
    float A, B, C, cb;

    if (fabs(_rotationM[6]) >= 1.0 - 0.0001)
    {
        if (_rotationM[6] < 0)
        {
            A = 0.0f;
            B = (float) M_PI_2;
            C = atan2f(_rotationM[1], _rotationM[4]);
        } else
        {
            A = 0.0f;
            B = -(float) M_PI_2;
            C = -atan2f(_rotationM[1], _rotationM[4]);
        }
    } else
    {
        B = atan2f(-_rotationM[6], sqrtf(_rotationM[0] * _rotationM[0] + _rotationM[3] * _rotationM[3]));
        cb = cosf(B);
        A = atan2f(_rotationM[3] / cb, _rotationM[0] / cb);
        C = atan2f(_rotationM[7] / cb, _rotationM[8] / cb);
    }

    _eulerAngles[0] = C;
    _eulerAngles[1] = B;
    _eulerAngles[2] = A;
}

int main()
{
    float rotationM[9];
    float eulerAngles[3];

    // 生成一个随机的旋转矩阵
    float x = (float) rand() / RAND_MAX * 2.0 - 1.0;
    float y = (float) rand() / RAND_MAX * 2.0 - 1.0;
    float z = (float) rand() / RAND_MAX * 2.0 - 1.0;
    float norm = sqrtf(x * x + y * y + z * z);
    x /= norm;
    y /= norm;
    z /= norm;

    float theta = (float) rand() / RAND_MAX * M_PI;
    float c = cosf(theta);
    float s = sinf(theta);
    float t = 1.0 - c;

    rotationM[0] = t * x * x + c;
    rotationM[1] = t * x * y - s * z;
    rotationM[2] = t * x * z + s * y;
    rotationM[3] = t * x * y + s * z;
    rotationM[4] = t * y * y + c;
    rotationM[5] = t * y * z - s * x;
    rotationM[6] = t * x * z - s * y;
    rotationM[7] = t * y * z + s * x;
    rotationM[8] = t * z * z + c;

    // 将旋转矩阵转换为欧拉角
    RotMatToEulerAngle(rotationM, eulerAngles);

    // 输出结果
    cout << "Random rotation matrix:" << endl;
    cout << rotationM[0] << " " << rotationM[1] << " " << rotationM[2] << endl;
    cout << rotationM[3] << " " << rotationM[4] << " " << rotationM[5] << endl;
    cout << rotationM[6] << " " << rotationM[7] << " " << rotationM[8] << endl;

    cout << "Calculated Euler angles:" << endl;
    cout << eulerAngles[0] << " " << eulerAngles[1] << " " << eulerAngles[2] << endl;

    return 0;
}
