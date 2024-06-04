#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H
#include "matrix.h"

class MatrixBuilder
{
private:
    static constexpr double degToRad = 1.0 / 180.0 * 3.1415;
public:
    static Matrix identity();
    static Matrix rotation(double x, double y, double z);
    static Matrix move(double x, double y, double z);
    static Matrix scale(double x, double y, double z);
};

#endif // MATRIXBUILDER_H
