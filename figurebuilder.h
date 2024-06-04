#ifndef FIGUREBUILDER_H
#define FIGUREBUILDER_H
#include "figure.h"

class FigureBuilder {
public:
    virtual Figure build() = 0;
};

#endif // FIGUREBUILDER_H
