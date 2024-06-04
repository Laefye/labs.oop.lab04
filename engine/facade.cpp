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
    delete this->_scene;
    this->_scene = 0;
    this->_scene = new Scene(reader->read(path));
    draw();
}

void Facade::loadScene(const std::string& path, const NormalizationParameters& params) {
    delete this->_scene;
    this->_scene = 0;
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

void Facade::setTransform(const Point& position, const Point& rotation, const Point& scale) {
    Scene& scene = this->scene();
    for (std::shared_ptr<Figure> figure : scene.figures()) {
        figure->setPosition(position);
        figure->setRotation(rotation);
        figure->setScale(scale);
    }
    draw();
}

void Facade::getTransform(Point& position, Point& rotation, Point& scale) {
    if (!_scene || _scene->figures().size() == 0) {
        position = Point(0, 0, 0);
        rotation = Point(0, 0, 0);
        scale = Point(1, 1, 1);
        return;
    }
    Scene& scene = this->scene();
    std::shared_ptr<Figure> figure = scene.figures()[0];
    position = figure->position();
    rotation = figure->rotation();
    scale = figure->scale();
}

bool Facade::isLoaded() {
    return _scene;
}
