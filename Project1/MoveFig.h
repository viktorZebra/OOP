#ifndef __MOVE_FIG_H__
#define __MOVE_FIG_H__

#include "ReadPoints.h"
#include "Figure.h"

typedef struct
{
    double dx;
    double dy;
    double dz;
}MoveVal;

void MovePoint(MyPoint& point, MoveVal val);
int MovePoints(MyPoint* arrayPoints, int countPoints, MoveVal val);
int MoveFigure(Figure& myFigure, MoveVal val);
int MoveArrayPoints(Points& points, MoveVal val);


#endif 