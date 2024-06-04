#include "edge.h"

Edge::Edge(const Vertex& begin, const Vertex& end) : _begin(begin.pointer()), _end(end.pointer()) {

}

Vertex Edge::begin() {
    return Vertex(_begin);
}

Vertex Edge::end() {
    return Vertex(_end);
}

const Vertex Edge::begin() const {
    return Vertex(_begin);
}

const Vertex Edge::end() const {
    return Vertex(_end);
}
