#include "Manager.h"

int TaskManager(Manager myManager, System::Windows::Forms::Panel^ Panel, System::Drawing::Graphics^ g)
{
    static Figure myFigure = InitFig(myFigure);
    int codeError = OK;

    switch (myManager.currentTask)
    {
        case LOAD_FILE:
            codeError = LoadModelFromFile(myFigure, myManager.fileName);
            break;

        case MOVE:
            codeError = MoveFigure(myFigure, myManager.moveVal);
            break;

        case SCALE:
            codeError = ScaleFigure(myFigure, myManager.scaleVal);
            break;

        case ROTATE:
            codeError = RotateFigure(myFigure, myManager.rotateVal);
            break;

        case DRAW:
            codeError = DrawFigure(myFigure, Panel, g);
            break;

        case FREE:
            FreeMemory(myFigure);
            break;

        default:
            codeError = ERROR_COMMAND;
    }

    return codeError;
}
