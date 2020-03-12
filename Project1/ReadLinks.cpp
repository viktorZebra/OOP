#include "ReadLinks.h"

int ReadLink(Link& link, FILE* file)
{
    int codeError = OK;

    if (fscanf(file, "%d %d", &link.from, &link.to) != 2)
    {
        codeError = INPUT_ERROR;
    }

    return codeError;
}

int ReadLinks(FILE* file, Link *arrayLinks, int countLinks)
{
    int codeError = OK;

    for (int i = 0; i < countLinks && !codeError; i++)
    {
        if (ReadLink(arrayLinks[i], file))
        {
            codeError = INPUT_ERROR;
        }
    }

    return codeError;
}

int ReadAllLinks(FILE* file, Links links)
{
    return ReadLinks(file, links.arrayLinks, links.countLinks);
}