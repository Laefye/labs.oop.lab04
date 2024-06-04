#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H
#include "../math/point.h"
#include "projection.h"

class Perspective : public Projection
{
public:
    Perspective() = default;
    Perspective(const Perspective& other) = default;

    Point project(const Point& point) override;
};

#endif // PERSPECTIVE_H
