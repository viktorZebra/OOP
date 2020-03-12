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
int ReadPoints(FILE* file, MyPoint* arrayPoints, int countPoints);
int ReadAllPoints(FILE* file, Points points);


