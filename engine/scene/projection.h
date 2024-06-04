#ifndef PROJECTION_H
#define PROJECTION_H
#include "../math/point.h"

class Projection {
public:
    virtual ~Projection() = default;
    virtual Point project(const Point& point) = 0;
};

#endif // PROJECTION_H
