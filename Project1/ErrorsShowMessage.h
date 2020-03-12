#ifndef __ERRORS_SHOW_MESSAGE_H__
#define __ERRORS_SHOW_MESSAGE_H__

#include <Windows.h>

#define OK 0
#define INPUT_ERROR 1
#define OPEN_FILE_ERROR 2
#define ALLOC_MEMORY_ERROR 3
#define ERROR_COMMAND 4

void ErrorsShowMessage(int codeError);

#endif