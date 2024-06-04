#ifndef FACADE_H
#define FACADE_H
#include "basefilereader.h"
#include "scene.h"
#include "normalizationparameters.h"
#include <string>
#include "scenedrawerbase.h"

class Facade
{
private:
    BaseFileReader* reader;
    Scene* _scene;
    SceneDrawerBase* drawer;
public:
    Facade(SceneDrawerBase* drawer);
    ~Facade();

    void loadScene(const std::string& path);
    void loadScene(const std::string& path, const NormalizationParameters& params);
    void draw();
    Scene& scene();
};

#endif // FACADE_H
