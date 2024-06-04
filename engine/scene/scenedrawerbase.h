#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H
#include "scene.h"
#include "projection.h"
#include "../math/point.h"

class SceneDrawerBase {
private:
    Projection* projection;
protected:
    Point project(const Point& point);
public:
    SceneDrawerBase();
    virtual ~SceneDrawerBase();

    void setProjection(Projection* projection);

    virtual void draw(const Scene& scene) = 0;
};

#endif // SCENEDRAWERBASE_H
