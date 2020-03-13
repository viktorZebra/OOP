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

int ReadLinks(Link *arrayLinks, int countLinks, FILE* file)
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

int ReadAllLinks(Links links, FILE* file)
{
    return ReadLinks(links.arrayLinks, links.countLinks, file);
}