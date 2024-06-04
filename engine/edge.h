#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"
#include "point.h"
#include <memory>

class Edge
{
private:
    std::shared_ptr<Point> _begin;
    std::shared_ptr<Point> _end;
public:
    Edge(const Vertex& begin, const Vertex& end);

    Vertex begin();
    Vertex end();
    const Vertex begin() const;
    const Vertex end() const;
};

#endif // EDGE_H
