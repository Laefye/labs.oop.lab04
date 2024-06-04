#include "scene.h"

Scene::Scene() {}

Scene::Scene(const Scene& scene) {
    _figures = scene._figures;
}

void Scene::add(const std::shared_ptr<Figure>& figure) {
    this->_figures.push_back(figure);
}

std::vector<std::shared_ptr<Figure>>& Scene::figures() {
    return _figures;
}

const std::vector<std::shared_ptr<Figure>>& Scene::figures() const {
    return this->_figures;
}
