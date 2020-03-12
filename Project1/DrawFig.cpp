#include "DrawFig.h"

void DrawFigure(Figure& myFigure, System::Windows::Forms::Panel^ Panel, Graphics^ g)
{
    ClearScreen(g);
    MyPoint firstPoint, secondPoint;

    for (int i = 0; i < myFigure.links.countLinks; i++)
    {
        firstPoint = GetPoint(myFigure.points.arrayPoints, myFigure.links.arrayLinks[i].from - 1); // не знаю как избежать двух точек
        secondPoint = GetPoint(myFigure.points.arrayPoints, myFigure.links.arrayLinks[i].to - 1);

        firstPoint = PointTransform(firstPoint, Panel);
        secondPoint = PointTransform(secondPoint, Panel);

        DrawLine(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y, g);
    }
}

MyPoint GetPoint(MyPoint* arrayPoints, int number)
{
    MyPoint dot = { arrayPoints[number].x, arrayPoints[number].y, arrayPoints[number].z };

    return dot;
}

MyPoint PointTransform(MyPoint point, System::Windows::Forms::Panel^ Panel)
{
    point.z = sqrt(2) / 2 * point.z;

    point.x = point.x - point.z;
    point.x = point.x + Panel->Width / 2;

    point.y = point.z - point.y;
    point.y = point.y + Panel->Height / 2;

    return point;
}

void DrawLine(double x1, double y1, double x2, double y2, Graphics^ g)
{
    Pen^ pen = CreatePen();

    PointF pt1(x1, y1);
    PointF pt2(x2, y2);

    MyDrawLine(g, pen, pt1, pt2);
}