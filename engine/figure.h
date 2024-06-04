#ifndef FIGURE_H
#define FIGURE_H
#include "sceneobject.h"
#include "vertex.h"
#include "edge.h"
#include "point.h"
#include <vector>

class Figure : public SceneObject
{
private:
    Point _position;
    Point _rotation;
    Point _scale;
    std::vector<Vertex> _vertices;
    std::vector<Edge> _edges;
public:
    Figure(const std::vector<Vertex>& vertices, const std::vector<Edge>& edges);
    Figure(const Figure& figure) = delete;

    Point position() const;
    void setPosition(const Point& point);
    Point rotation() const;
    void setRotation(const Point& point);
    Point scale() const;
    void setScale(const Point& point);

    std::vector<Vertex>& vertices();
    std::vector<Edge>& edges();
    const std::vector<Vertex>& vertices() const;
    const std::vector<Edge>& edges() const;


    Point transform(const Point& point) const override;
};

#endif // FIGURE_H
