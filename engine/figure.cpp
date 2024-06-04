#include "figure.h"
#include "matrix.h"
#include "matrixbuilder.h"

Figure::Figure(const std::vector<Vertex>& vertices, const std::vector<Edge>& edges) : _vertices(vertices), _edges(edges) {
    _position = Point(0, 0, 0);
    _rotation = Point(0, 0, 0),
    _scale = Point(10, 10, 10);
}

Point Figure::position() const {
    return _position;
}
void Figure::setPosition(const Point& point) {
    _position = point;
}

Point Figure::rotation() const {
    return _rotation;
}

void Figure::setRotation(const Point& point) {
    _rotation = point;
}

Point Figure::scale() const {
    return _scale;
}

void Figure::setScale(const Point& point) {
    _scale = point;
}

std::vector<Vertex>& Figure::vertices() {
    return _vertices;
}

std::vector<Edge>& Figure::edges() {
    return _edges;
}

const std::vector<Vertex>& Figure::vertices() const {
    return _vertices;
}

const std::vector<Edge>& Figure::edges() const {
    return _edges;
}

Point Figure::transform(const Point& point) const {
    Matrix translate = MatrixBuilder::move(_position.X(), _position.Y(), _position.Z());
    Matrix rotate = MatrixBuilder::rotation(_rotation.X(), _rotation.Y(), _rotation.Z());
    Matrix scale = MatrixBuilder::scale(_scale.X(), _scale.Y(), _scale.Z());
    return rotate.transform(scale.transform(translate.transform(point)));
}
