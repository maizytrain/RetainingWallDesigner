#include <QGraphicsScene>
#include <vector>

void DrawLines(QGraphicsScene *scene, std::vector<float> xpoints, std::vector<float> ypoints)
{
    scene->clear();

    int size = xpoints.size();
    for (int i{0}; i < size-1; i++)
        scene->addLine(xpoints[i], ypoints[i], xpoints[i+1], ypoints[i+1]);
    scene->addLine(xpoints[size-1], ypoints[size-1], xpoints[0], ypoints[0]);
}
