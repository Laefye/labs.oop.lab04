#ifndef MATRIX_H
#define MATRIX_H
#include "point.h"
#include <initializer_list>

class Matrix
{
public:
    constexpr static int size = 4;
private:
    double values[size][size];

    void set(const Matrix& other);
public:
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<double>> list);

    void set(int row, int column, double val);

    double get(int row, int column) const;

    Point transform(const Point& point) const;

    Matrix& operator*=(const Matrix& other);
};

Matrix operator*(const Matrix& a, const Matrix& b);

#endif // MATRIX_H
