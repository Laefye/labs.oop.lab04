#include "facade.h"
#include "filereader.h"
#include "exceptions/scenenotloadedexception.h"

Facade::Facade(SceneDrawerBase* drawer) {
    this->reader = new FileReader();
    this->_scene = 0;
    this->drawer = drawer;
}

Facade::~Facade() {
    delete this->reader;
    delete this->_scene;
}

void Facade::loadScene(const std::string& path) {
    this->_scene = new Scene(reader->read(path));
}

void Facade::loadScene(const std::string& path, const NormalizationParameters& params) {
    this->_scene = new Scene(reader->read(path, params));
}

Scene& Facade::scene() {
    if (!_scene) {
        throw SceneNotLoadedException();
    }
    return *_scene;
}

void Facade::draw() {
    drawer->draw(scene());
}
