#ifndef FIGUREBUILDER_H
#define FIGUREBUILDER_H
#include "figure.h"
#include <memory>

class FigureBuilder {
public:
    virtual std::shared_ptr<Figure> build() = 0;
};

#endif // FIGUREBUILDER_H
