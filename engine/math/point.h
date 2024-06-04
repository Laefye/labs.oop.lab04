#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x;
    double y;
    double z;
public:
    Point();
    Point(double x, double y, double z);
    Point(const Point& point);

    Point& operator=(const Point& other);

    double X() const;
    double Y() const;
    double Z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
};

#endif // POINT_H
