#include "LoadFig.h"
#include <cstdio>

int LoadModelFromFile(Figure& myFigure, char* fileName)
{
	Figure bufFigure = InitFig(bufFigure);

	FILE* file = fopen(fileName, "r");

	if (!file)
	{
		return OPEN_FILE_ERROR;
	}

	int codeError = ReadCount(bufFigure.points, bufFigure.links, file);

	if (!codeError)
	{
		codeError = AllocMemmoryFig(bufFigure.points, bufFigure.links);
	}
	
	if (!codeError)
	{
		codeError = ReadAllPoints(bufFigure.points, file);
	}

	if (!codeError)
	{
		codeError = ReadAllLinks(bufFigure.links, file);
	}

	if (codeError)
	{
		FreeMemory(bufFigure);
	}
	else
	{
		FreePrevFigure(myFigure);
		InterceptionData(myFigure, bufFigure);
	}

	fclose(file);

	return codeError;
}

int ReadCount(Points& points, Links& links, FILE *file)
{
	int codeError = OK;
	int countPoints = 0;
	int countLinks = 0;

	if (fscanf(file, "%d %d", &countPoints, &countLinks) != 2)
	{
		codeError = INPUT_ERROR;
	}

	if (countPoints <= 0 || countLinks <= 0)
	{
		codeError = INPUT_ERROR;
	}

	if (!codeError)
	{
		links.countLinks = countLinks;
		points.countPoints = countPoints;
	}

	return codeError;
}

Figure& InitFig(Figure& myFigure)
{
	myFigure.points.countPoints = 0;
	myFigure.points.arrayPoints = NULL;

	myFigure.links.countLinks = 0;
	myFigure.links.arrayLinks = NULL;

	return myFigure;
}

void InterceptionData(Figure& myFigure, Figure& bufFigure)
{
	InterceptionPoints(myFigure.points, bufFigure.points);
	InterceptionLinks(myFigure.links, bufFigure.links);
}

void InterceptionPoints(Points& points, Points &bufPoints)
{
	points.countPoints = bufPoints.countPoints;
	points.arrayPoints = bufPoints.arrayPoints;
	bufPoints.arrayPoints = NULL;
}

void InterceptionLinks(Links& links, Links& bufLinks)
{
	links.countLinks = bufLinks.countLinks;
	links.arrayLinks = bufLinks.arrayLinks;
	bufLinks.arrayLinks = NULL;
}
