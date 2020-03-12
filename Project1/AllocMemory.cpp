#include "AllocMemory.h"

int AllocMemmoryFig(Points& points, Links& links)
{
    int codeError = OK;

    points.arrayPoints = (MyPoint*) calloc(points.countPoints, sizeof(MyPoint));
    links.arrayLinks = (Link*) calloc(links.countLinks, sizeof(Link));

    if (!points.arrayPoints || !links.arrayLinks)
        codeError = ALLOC_MEMORY_ERROR;

    return codeError;
}

void FreeAllArray(Points& points, Links& links)
{
    if (points.arrayPoints)
        free(points.arrayPoints);

    if (links.arrayLinks)
        free(links.arrayLinks);
}

void FreeMemory(Figure& myFigure)
{
    FreeAllArray(myFigure.points, myFigure.links);
}

void FreeBufFigure(Figure& myFigure)
{
    FreeMemory(myFigure);
}

void FreePrevFigure(Figure& myFigure)
{
    FreeMemory(myFigure);
}