#include "RotateFig.h"

double DegToRadCos(double angle)
{
    return cos(angle * M_PI / 180);
}

double DegToRadSin(double angle)
{
    return sin(angle * M_PI / 180);
}

void RotateOX(MyPoint& point, double angle)
{
    double cosAngle = DegToRadCos(angle);
    double sinAngle = DegToRadSin(angle);

    point.y = point.y + cosAngle + point.z * sinAngle;
    point.z = -point.y * sinAngle + point.z * cosAngle;
}

void RotateOY(MyPoint& point, double angle)
{
    double cosAngle = DegToRadCos(angle);
    double sinAngle = DegToRadSin(angle);

    point.x = point.x * cosAngle + point.z * sinAngle;
    point.z = -point.x * sinAngle + point.z * cosAngle;
}

void RotateOZ(MyPoint& point, double angle)
{
    double cosAngle = DegToRadCos(angle);
    double sinAngle = DegToRadSin(angle);

    point.x = point.x * cosAngle + point.y * sinAngle;
    point.y = -point.x * sinAngle + point.y * cosAngle;
}

int RotatePoints(MyPoint* arrayPoints, int countPoints, RotateVal val)
{
    int codeError = OK;

    if (arrayPoints)
    {
        for (int i = 0; i < countPoints; i++)
        {
            RotateOX(arrayPoints[i], val.angleX);
            RotateOY(arrayPoints[i], val.angleY);
            RotateOZ(arrayPoints[i], val.angleZ);
        }
    }
    else
    {
        codeError = INPUT_ERROR;
    }

    return codeError;
}

int RotateFigure(Figure& Myfigure, RotateVal val)
{
    return RotatePoints(Myfigure.points.arrayPoints, Myfigure.points.countPoints, val);
}