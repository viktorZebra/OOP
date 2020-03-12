#include "LoadFig.h"
#include <cstdio>

int LoadModelFromFile(Figure& myFigure, char* fileName)
{
	FreePrevFigure(myFigure);

	FILE* file = fopen(fileName, "r");

	if (!file)
	{
		return OPEN_FILE_ERROR;
	}

	int codeError = ReadCount(myFigure.points, myFigure.links, file);

	if (!codeError)
	{
		codeError = AllocMemmoryFig(myFigure.points, myFigure.links);
	}
	
	if (!codeError)
	{
		codeError = ReadAllPoints(file, myFigure.points);
	}

	if (!codeError)
	{
		codeError = ReadAllLinks(file, myFigure.links);
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

/*void CopyFig(Figure& myFigure, Figure& bufFigure)
{
	myFigure.links.countLinks = bufFigure.links.countLinks;
	myFigure.points.countPoints = bufFigure.points.countPoints;

	for (int i = 0; i < bufFigure.links.countLinks; i++)
	{
		myFigure.links.arrayLinks[i].from = bufFigure.links.arrayLinks[i].from;
		myFigure.links.arrayLinks[i].to = bufFigure.links.arrayLinks[i].to;
	}

	for (int i = 0; i < bufFigure.points.countPoints; i++)
	{
		myFigure.points.arrayPoints[i].x = bufFigure.points.arrayPoints[i].x;
		myFigure.points.arrayPoints[i].y = bufFigure.points.arrayPoints[i].y;
		myFigure.points.arrayPoints[i].z = bufFigure.points.arrayPoints[i].z;

		myFigure.points.arrayPoints[i].number = bufFigure.points.arrayPoints[i].number;
	}
}*/

