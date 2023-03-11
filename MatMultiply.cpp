#include <iostream>

static void MatMultiply(const float* _matrix1, const float* _matrix2, float* _matrixOut,
                        const int _m, const int _l, const int _n)
{
    float tmp;
    int i, j, k;
    for (i = 0; i < _m; i++)
    {
        for (j = 0; j < _n; j++)
        {
            tmp = 0.0f;
            for (k = 0; k < _l; k++)
            {
                tmp += _matrix1[_l * i + k] * _matrix2[_n * k + j];
            }
            _matrixOut[_n * i + j] = tmp;
        }
    }
}

int main() {
    const int m = 3;
    const int l = 4;
    const int n = 2;
    float matrix1[m * l] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f};
    float matrix2[l * n] = {1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f};
    float matrixOut[m * n] = {0.0f};

    MatMultiply(matrix1, matrix2, matrixOut, m, l, n);

    std::cout << "Result Matrix: " << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrixOut[n * i + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}