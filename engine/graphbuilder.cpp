#include "graphbuilder.h"

GraphBuilder::GraphBuilder(std::vector<std::vector<double>>& values) : values(values) {

}

std::shared_ptr<Figure> GraphBuilder::build() {
    std::vector<std::vector<Vertex>> rows;
    std::vector<Edge> edges;
    for (size_t i = 0; i < values.size(); i++) {
        std::vector<Vertex> row;
        for (size_t j = 0; j < values.size(); j++) {
            row.push_back(Vertex(Point(i, j, values[i][j])));
        }
        rows.push_back(row);
    }
    for (size_t i = 0; i < values.size(); i++) {
        for (size_t j = 1; j < values.size(); j++) {
            edges.push_back(Edge(rows[i][j - 1], rows[i][j]));
        }
    }
    for (size_t i = 1; i < values.size(); i++) {
        for (size_t j = 0; j < values.size(); j++) {
            edges.push_back(Edge(rows[i - 1][j], rows[i][j]));
        }
    }
    std::vector<Vertex> vertices;
    for (std::vector<Vertex>& row : rows) {
        for (Vertex& vertex : row) {
            vertices.push_back(vertex);
        }
    }
    return std::make_shared<Figure>(vertices, edges);
}
