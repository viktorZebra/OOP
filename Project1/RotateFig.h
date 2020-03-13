#ifndef __ROTATE_FIG_H__
#define __ROTATE_FIG_H__

#define _USE_MATH_DEFINES // для C++
#include <cmath>

#include "ReadPoints.h"
#include "Figure.h"

typedef struct
{
    double angleX;
    double angleY;
    double angleZ;
}RotateVal;

double DegToRadCos(double angle);
double DegToRadSin(double angle);

void RotateOX(MyPoint& point, double angle);
void RotateOY(MyPoint& point, double angle);
void RotateOZ(MyPoint& point, double angle);

int RotatePoints(MyPoint* arrayPoints, int countPoints, RotateVal val);
int RotateFigure(Figure& Myfigure, RotateVal val);
int RotateArrayPoints(Points& points, RotateVal val);

#endif