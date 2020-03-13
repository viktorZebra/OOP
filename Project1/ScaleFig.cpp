#include "ScaleFig.h"

void ScalePoint(MyPoint& point, ScaleVal val)
{
    point.x *= val.kx;
    point.y *= val.ky;
    point.z *= val.kz;
}

int ScalePoints(MyPoint* arrayPoints, int countPoints, ScaleVal val)
{
    int codeError = OK;

    if (arrayPoints)
    {
        for (int i = 0; i < countPoints; i++)
            ScalePoint(arrayPoints[i], val);
    }
    else
    {
        codeError = INPUT_ERROR;
    }

    return codeError;
}

int ScaleFigure(Figure& myFigure, ScaleVal val)
{
    return ScaleArrayPoints(myFigure.points, val);
}

int ScaleArrayPoints(Points& points, ScaleVal val)
{
    return ScalePoints(points.arrayPoints, points.countPoints, val);
}