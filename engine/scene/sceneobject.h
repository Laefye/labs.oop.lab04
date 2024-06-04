#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H
#include "../math/point.h"

class SceneObject {
public:
    virtual Point transform(const Point& point) const = 0;
};

#endif // SCENEOBJECT_H
