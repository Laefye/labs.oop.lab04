#ifndef SCENENOTLOADEDEXCEPTION_H
#define SCENENOTLOADEDEXCEPTION_H
#include <exception>

class SceneNotLoadedException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Scene not loaded";
    }
};

#endif // SCENENOTLOADEDEXCEPTION_H
