#include "MoveFig.h"

void MovePoint(MyPoint& point, MoveVal val)
{
    point.x += val.dx;
    point.y += val.dy;
    point.z += val.dz;
}

int MovePoints(MyPoint* arrayPoints, int countPoints, MoveVal val)
{
    int codeError = OK;

    if (arrayPoints)
    {
        for (int i = 0; i < countPoints; i++)
            MovePoint(arrayPoints[i], val);
    }
    else
    {
        codeError = INPUT_ERROR;
    }

    return codeError;
}

int MoveFigure(Figure& myFigure, MoveVal val)
{
    return MovePoints(myFigure.points.arrayPoints, myFigure.points.countPoints, val);
}