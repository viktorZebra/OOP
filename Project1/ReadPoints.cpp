#include "ReadPoints.h"

int ReadPoints(MyPoint* arrayPoints, int countPoints, FILE* file)
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

int ReadAllPoints(Points points, FILE* file)
{
	return ReadPoints(points.arrayPoints, points.countPoints, file);
}