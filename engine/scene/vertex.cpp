#include "vertex.h"

Vertex::Vertex(const Point& point) {
    _position = std::make_shared<Point>(point);
}

Vertex::Vertex(const std::shared_ptr<Point>& point) {
    _position = point;
}

Vertex::Vertex(const Vertex& vertex) {
    _position = vertex._position;
}

Point Vertex::position() const {
    return *_position;
}

void Vertex::setPosition(const Point& point) {
    *_position = point;
}

const std::shared_ptr<Point> Vertex::pointer() const {
    return _position;
}

std::shared_ptr<Point> Vertex::pointer() {
    return _position;
}
