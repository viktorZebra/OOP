#pragma once
using namespace System::Drawing;

void ClearScreen(Graphics^ g);
void MyDrawLine(Graphics^ g, Pen^ pen, PointF pt1, PointF pt2);
Pen^ CreatePen();