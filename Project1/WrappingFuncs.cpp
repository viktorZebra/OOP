#include "WrappingFuncs.h"

void ClearScreen(Graphics^ g)
{
    g->Clear(Color::White);
}

void MyDrawLine(Graphics^ g, Pen^ pen, PointF pt1, PointF pt2)
{
    g->DrawLine(pen, pt1, pt2);
}

Pen^ CreatePen()
{
    return gcnew System::Drawing::Pen(Color::Black, 1);
}