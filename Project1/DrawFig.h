#ifndef __DRAW_FIG_H__
#define __DRAW_FIG_H__

using namespace System::Drawing;
//using namespace System::Windows::Forms;
#include "Figure.h"
#include "WrappingFuncs.h"
#include <cmath>

typedef struct
{
	int width;
	int height;
}DrawFormInfo;

typedef Graphics^ MyGraphics;
typedef System::Windows::Forms::Panel^ MyPanel;

MyPoint GetFromPoint(MyPoint* arrayPoints, Link* arrayLinks, int indexLink);
MyPoint GetToPoint(MyPoint* arrayPoints, Link* arrayLinks, int indexLink);
MyPoint PointTransform(MyPoint point, DrawFormInfo Info);
int DrawFigure(Figure& myFigure, MyPanel Panel, MyGraphics g);
void DrawLine(double x1, double y1, double x2, double y2, MyGraphics g);
void Draw(Links& links, Points& points, MyPanel Panel, MyGraphics g);

#endif 
