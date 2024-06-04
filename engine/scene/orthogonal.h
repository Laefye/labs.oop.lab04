#ifndef ORTHOGONAL_H
#define ORTHOGONAL_H
#include "../math/point.h"
#include "projection.h"

class Orthogonal : public Projection
{
public:
    Orthogonal() = default;
    Orthogonal(const Orthogonal& other) = default;

    Point project(const Point& point) override;
};

#endif // ORTHOGONAL_H
