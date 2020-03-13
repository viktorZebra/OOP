#pragma once

#include <cstdio>

#include "ErrorsShowMessage.h"

typedef struct
{
	double x;
	double y;
	double z;

	int number;
}MyPoint;

typedef struct
{
	MyPoint* arrayPoints;
	int countPoints;
}Points;


int ReadPoint(MyPoint& point, FILE* file);
int ReadPoints(MyPoint* arrayPoints, int countPoints, FILE* file);
int ReadAllPoints(Points points, FILE* file);


