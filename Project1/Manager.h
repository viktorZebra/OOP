#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "MoveFig.h"
#include "ScaleFig.h"
#include "RotateFig.h"
#include "LoadFig.h"
#include "AllocMemory.h"
#include "DrawFig.h"
#include "ErrorsShowMessage.h"

typedef enum
{
    FREE,
    LOAD_FILE,
    DRAW,
    MOVE,
    SCALE,
    ROTATE
}Task;

typedef struct
{
    Task currentTask;
    union
    {
        char *fileName;
        MoveVal moveVal;
        ScaleVal scaleVal;
        RotateVal rotateVal;
    };
}Manager;

int TaskManager(Manager myManager, System::Windows::Forms::Panel^ Panel, System::Drawing::Graphics^ g);

#endif 
