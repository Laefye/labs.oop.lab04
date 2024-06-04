#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H
#include <QWidget>
#include "engine/scene/scene.h"
#include "engine/scene/scenedrawerbase.h"

class QtSceneDrawer : public QWidget, public SceneDrawerBase
{
private:
    const Scene* scene;
public:
    QtSceneDrawer(QWidget* parent = 0);

    void draw(const Scene& scene) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // QTSCENEDRAWER_H
