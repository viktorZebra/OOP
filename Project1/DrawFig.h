#ifndef __DRAW_FIG_H__
#define __DRAW_FIG_H__

using namespace System::Drawing;
//using namespace System::Windows::Forms;
#include "Figure.h"
#include "WrappingFuncs.h"
#include <cmath>

MyPoint GetPoint(MyPoint* arrayPoints, int number);
MyPoint PointTransform(MyPoint point, System::Windows::Forms::Panel^ Panel);
void DrawFigure(Figure& myFigure, System::Windows::Forms::Panel^ Panel, Graphics^ g);
void DrawLine(double x1, double y1, double x2, double y2, Graphics^ g);

#endif 
