#include "perspective.h"
#define PERSPECTIVE_K 900

Point Perspective::project(const Point& point) {
    if (point.Y() > 0) {
        return Point(point.X() * PERSPECTIVE_K / (point.Y() + PERSPECTIVE_K), point.Y(), point.Z() * PERSPECTIVE_K / (point.Y() + PERSPECTIVE_K));
    } else {
        return point;
    }
}
