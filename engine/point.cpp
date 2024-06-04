#include "point.h"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& point) {
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

double Point::X() const {
    return x;
}

double Point::Y() const {
    return y;
}

double Point::Z() const {
    return z;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setZ(double z) {
    this->z = z;
}
