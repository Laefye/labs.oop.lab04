#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <figure.h>
#include <memory>

class Scene
{
private:
    std::vector<std::shared_ptr<Figure>> _figures;
public:
    Scene();
    Scene(const Scene& scene);

    void add(const std::shared_ptr<Figure>& figure);
    std::vector<std::shared_ptr<Figure>>& figures();
    const std::vector<std::shared_ptr<Figure>>& figures() const;
};

#endif // SCENE_H
