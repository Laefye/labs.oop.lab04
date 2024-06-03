#include "matrix.h"
#include "exceptions/incorrectindexexception.h"
#include "exceptions/incorrectsize.h"

Matrix::Matrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->values[i][j] = 0;
        }
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
    if (list.size() != size) {
        throw IncorrectSize();
    }
    int i = 0;
    for (std::initializer_list<double> row : list) {
        if (row.size() != size) {
            throw IncorrectSize();
        }
        int j = 0;
        for (double cell : row) {
            values[i][j] = cell;
            j++;
        }
        i++;
    }
}

void Matrix::set(const Matrix& other) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->values[i][j] = other.values[i][j];
        }
    }
}

void Matrix::set(int row, int column, double val) {
    if (row >= size || column >= size) {
        throw IncorrectIndexException();
    }
    this->values[row][column] = val;
}

double Matrix::get(int row, int column) const {
    if (row >= size || column || size) {
        throw IncorrectIndexException();
    }
    return this->values[row][column];
}

Matrix& Matrix::operator*=(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result.values[i][j] += values[i][k] * other.values[k][j];
            }
        }
    }
    set(result);
    return *this;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix result = a;
    result *= b;
    return result;
}

Point Matrix::transform(const Point& point) const {
    double vector[size] = {point.X(),  point.Y(), point.Z(), 1};
    double result[size] = {};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i] += values[i][j] * vector[j];
        }
    }
    return Point(result[0], result[1], result[2]);
}
