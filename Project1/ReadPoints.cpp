#include "ReadPoints.h"

int ReadPoints(FILE *file, MyPoint* arrayPoints, int countPoints)
{
	int codeError = OK;

	for (int i = 0; i < countPoints && !codeError; i++)
	{
		if (ReadPoint(arrayPoints[i], file))
		{
			codeError = INPUT_ERROR;
		}
	}

	return codeError;
}

int ReadPoint(MyPoint &point, FILE* file)
{
	int codeError = OK;

	if (fscanf(file, "%lf %lf %lf %d", &point.x, &point.y, &point.z, &point.number) != 4)
	{
		codeError = INPUT_ERROR;
	}

	return codeError;
}

int ReadAllPoints(FILE* file, Points points)
{
	return ReadPoints(file, points.arrayPoints, points.countPoints);
}