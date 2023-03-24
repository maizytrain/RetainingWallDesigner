#include <QGraphicsScene>
#include <vector>
#include <QDebug>

void DrawLines(QGraphicsScene *scene, std::vector<float> xpoints, std::vector<float> ypoints, float embedment, float topAngle)
{
    scene->clear();

    int size = xpoints.size();
    for (int i{0}; i < size-1; i++)
        scene->addLine(xpoints[i], ypoints[i], xpoints[i+1], ypoints[i+1]);
    scene->addLine(xpoints[size-1], ypoints[size-1], xpoints[0], ypoints[0]);

    std::vector<float> lower;
    lower.push_back(xpoints[size-1] * -.8);
    lower.push_back(embedment * 50);
    if (lower[1] <= ypoints[1])
        lower.push_back(xpoints[1]);
    else
        lower.push_back(xpoints[2]);
    scene->addLine(lower[0], lower[1], lower[2], lower[1]);

    std::vector<float> upper;
    upper.push_back(xpoints[4]);
    upper.push_back(ypoints[4]);
    upper.push_back(xpoints[6] * 1.4);
    upper.push_back(upper[1] + (upper[2] - upper[0]) * tan(topAngle * 3.14 / 180));
    qDebug() << sin(topAngle);
    qDebug() << upper[3];
    scene->addLine(upper[0], upper[1], upper[2], upper[3]);
}
