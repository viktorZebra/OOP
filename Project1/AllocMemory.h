#pragma once

#include "Figure.h"

int AllocMemmoryFig(Points& points, Links& links);
void FreeMemory(Figure &myFigure);
void FreeAllArray(Points& points, Links& links);
void FreeBufFigure(Figure& myFigure);
void FreePrevFigure(Figure& myFigure);