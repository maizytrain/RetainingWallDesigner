#ifndef CONCRETEDRAWER_H
#define CONCRETEDRAWER_H

#include <vector>
#include <QGraphicsScene>

void DrawWallAndSoil(QGraphicsScene *scene, std::vector<float> xpoints, std::vector<float> ypoints, float embedment, float topAngle);

#endif // CONCRETEDRAWER_H
