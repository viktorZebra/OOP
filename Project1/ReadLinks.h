#ifndef __READ_LINKS_H__
#define __READ_LINKS_H__

#include <cstdio>

#include "ErrorsShowMessage.h"

typedef struct
{
	int from;
	int to;
}Link;

typedef struct
{
	Link* arrayLinks;
	int countLinks;
}Links;

int ReadLinks(FILE* file, Link *arrayLinks, int countLinks);
int ReadLink(Link &link, FILE* file);
int ReadAllLinks(FILE* file, Links links);

#endif 