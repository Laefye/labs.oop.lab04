#include "scenedrawerbase.h"
#include "orthogonal.h"

SceneDrawerBase::SceneDrawerBase() {
    projection = new Orthogonal();
}

SceneDrawerBase::~SceneDrawerBase() {
    delete projection;
}

Point SceneDrawerBase::project(const Point& point) {
    return projection->project(point);
}

void SceneDrawerBase::setProjection(Projection* projection) {
    delete this->projection;
    this->projection = projection;
}
