#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H
#include "figurebuilder.h"
#include "figure.h"

class GraphBuilder : public FigureBuilder
{
private:
    std::vector<std::vector<double>>& values;
public:
    GraphBuilder(std::vector<std::vector<double>>& values);

    std::shared_ptr<Figure> build() override;
};

#endif // GRAPHBUILDER_H
