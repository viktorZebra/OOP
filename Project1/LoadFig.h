#ifndef __LOAD_FIG_H__
#define __LOAD_FIG_H__

#include <cstdio>


#include "Figure.h"
#include "ErrorsShowMessage.h"
#include "AllocMemory.h"

int ReadCount(Points& points, Links& links, FILE* file);
int LoadModelFromFile(Figure& myFigure, char* fileName);
Figure& InitFig(Figure& myFigure);
void InterceptionData(Figure& myFigure, Figure& bufFigure);
void InterceptionPoints(Points& points, Points& bufPoints);
void InterceptionLinks(Links& links, Links& bufLinks);

#endif
