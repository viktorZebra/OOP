#include "DrawFig.h"

int DrawFigure(Figure& myFigure, MyPanel Panel, MyGraphics g)
{
    ClearScreen(g);
    Draw(myFigure.links, myFigure.points, Panel, g);

    return OK;
}

MyPoint GetFromPoint(MyPoint* arrayPoints, Link* arrayLinks, int indexLink)
{
    int indexPoint = arrayLinks[indexLink].from - 1;
    MyPoint dot = { arrayPoints[indexPoint].x, arrayPoints[indexPoint].y, arrayPoints[indexPoint].z };

    return dot;
}

MyPoint GetToPoint(MyPoint* arrayPoints, Link* arrayLinks, int indexLink)
{
    int indexPoint = arrayLinks[indexLink].to - 1;
    MyPoint dot = { arrayPoints[indexPoint].x, arrayPoints[indexPoint].y, arrayPoints[indexPoint].z };

    return dot;
}

MyPoint PointTransform(MyPoint point, DrawFormInfo Info)
{
    point.z = sqrt(2) / 2 * point.z;

    point.x = point.x - point.z;
    point.x = point.x + Info.width / 2;

    point.y = point.z - point.y;
    point.y = point.y + Info.height / 2;

    return point;
}

void DrawLine(double x1, double y1, double x2, double y2, MyGraphics g) // обертка 
{
    Pen^ pen = CreatePen();

    PointF pt1(x1, y1);
    PointF pt2(x2, y2);

    MyDrawLine(g, pen, pt1, pt2);
}

void Draw(Links& links, Points& points, MyPanel Panel, MyGraphics g)
{
    MyPoint firstPoint, secondPoint;

    DrawFormInfo Info;
    Info.width = Panel->Width;
    Info.height = Panel->Height;

    for (int i = 0; i < links.countLinks; i++)
    {
        firstPoint = GetFromPoint(points.arrayPoints, links.arrayLinks, i);
        secondPoint = GetToPoint(points.arrayPoints, links.arrayLinks, i);

        firstPoint = PointTransform(firstPoint, Info);
        secondPoint = PointTransform(secondPoint, Info);

        DrawLine(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y, g);
    }
}