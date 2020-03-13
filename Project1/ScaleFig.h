#ifndef __SCALE_FIG_H__
#define __SCALE_FIG_H__

#include "ReadPoints.h"
#include "Figure.h"

typedef struct 
{
    double kx;
    double ky;
    double kz;
}ScaleVal;

void ScalePoint(MyPoint& point, ScaleVal val);
int ScalePoints(MyPoint* arrayPoints, int countPoints, ScaleVal val);
int ScaleFigure(Figure& myFigure, ScaleVal val);
int ScaleArrayPoints(Points& points, ScaleVal val);

#endif 
