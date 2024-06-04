#ifndef VERTEX_H
#define VERTEX_H
#include "point.h"
#include <memory>


class Vertex
{
private:
    std::shared_ptr<Point> _position;
public:
    Vertex(const Point& point);
    Vertex(const std::shared_ptr<Point>& point);
    Vertex(const Vertex& vertex);

    Point position() const;
    void setPosition(const Point& point);

    std::shared_ptr<Point> pointer();
    const std::shared_ptr<Point> pointer() const;
};

#endif // VERTEX_H
