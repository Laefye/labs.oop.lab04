#ifndef FACADE_H
#define FACADE_H
#include "basefilereader.h"
#include "scene.h"
#include "normalizationparameters.h"
#include <string>
#include "scenedrawerbase.h"
#include "point.h"

class Facade
{
private:
    BaseFileReader* reader;
    Scene* _scene;
    SceneDrawerBase* drawer;

    Scene& scene();
public:
    Facade(SceneDrawerBase* drawer);
    ~Facade();

    void loadScene(const std::string& path);
    void loadScene(const std::string& path, const NormalizationParameters& params);
    void draw();
    void setTransform(const Point& position, const Point& rotation, const Point& scale);
    void getTransform(Point& position, Point& rotation, Point& scale);
};

#endif // FACADE_H
