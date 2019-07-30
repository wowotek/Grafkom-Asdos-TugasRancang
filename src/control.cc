#include <iostream>
#include <vector>
#include <algorithm>
#include <GL/glut.h>

#include "control.hh"

Camera * cameraP;
ControlKey * controlKeyP;
MousePos * mousePosP;
bool cursorCentered = false;

void
InitControl(Camera * initCamera, ControlKey * initControlKey, MousePos * initMousePos){
    cameraP = initCamera;
    controlKeyP = initControlKey;
    mousePosP = initMousePos;

    controlKeyP->ResetKeys();
}

void ToggleCursorCenter()
{
    cursorCentered = !cursorCentered;
}

void
MouseButtonEventHandler(int, int, int, int)
{
}

void
MouseDragEventHandler(int posX, int posY)
{
    if(!cursorCentered) return;

    mousePosP->pX = posX;
    mousePosP->pY = posY;
    mousePosP->calculate();

    cameraP->RotateYaw(mousePosP->cX);
    cameraP->RotatePitch(mousePosP->cY);
}

void
MouseMoveEventHandler(int posX, int posY)
{
    if(!cursorCentered) return;

    mousePosP->pX = posX;
    mousePosP->pY = posY;
    mousePosP->calculate();

    cameraP->RotateYaw(mousePosP->cX);
    cameraP->RotatePitch(mousePosP->cY);
}

void
KeyboardDownEventHandler(unsigned char key, int, int)
{
    if ((key == 'w' || key == 'W') && !controlKeyP->w.state)
        controlKeyP->w.PressKey();
    else
    if ((key == 'a' || key == 'A') && !controlKeyP->a.state)
        controlKeyP->a.PressKey();
    else
    if ((key == 's' || key == 'S') && !controlKeyP->s.state)
        controlKeyP->s.PressKey();
    else
    if ((key == 'd' || key == 'D') && !controlKeyP->d.state)
        controlKeyP->d.PressKey();
    else
    if ((key == 't' || key == 'T'))
        ToggleCursorCenter();
    else
    if ( key == 'q' || key == 'Q')
        glutDestroyWindow(glutGetWindow());
    else
    if ((key == ' '              ) && !controlKeyP->space.state)
        controlKeyP->space.PressKey();
}

void
KeyboardUpEventHandler(unsigned char key, int, int)
{
    if ((key == 'w' || key == 'W') && controlKeyP->w.state)
        controlKeyP->w.ReleaseKey();
    else
    if ((key == 'a' || key == 'A') && controlKeyP->a.state)
        controlKeyP->a.ReleaseKey();
    else
    if ((key == 's' || key == 'S') && controlKeyP->s.state)
        controlKeyP->s.ReleaseKey();
    else
    if ((key == 'd' || key == 'D') && controlKeyP->d.state)
        controlKeyP->d.ReleaseKey();
    else
    if ((key == ' '              ) && controlKeyP->space.state)
        controlKeyP->space.ReleaseKey();
}

void
KeyboardSpecialDownEventHandler(int key, int, int)
{
    if(!controlKeyP->IsSpecKeyPressed()){
        if (key == 112 && !controlKeyP->lshift.state) 
            controlKeyP->lshift.PressKey(); else
        if (key == 114 && !controlKeyP->lctrl.state)
            controlKeyP->lctrl.PressKey();
    }
}

void
KeyboardSpecialUpEventHandler(int key, int, int)
{
    if(controlKeyP->IsSpecKeyPressed()){
        if (key == 112 && controlKeyP->lshift.state)
            controlKeyP->lshift.ReleaseKey(); else
        if (key == 114 && controlKeyP->lctrl.state)
            controlKeyP->lctrl.ReleaseKey();
    }
}

#define MOVESPEED 0.005
#define RUNSPEED  0.2
float moveSpeed = 0.2;

void
ControlCallback()
{
    // Check if running;
    if(controlKeyP->lshift.state) moveSpeed = RUNSPEED;
    else moveSpeed = MOVESPEED;

    // Movement
    if(controlKeyP->w.state)     cameraP->Move(moveSpeed);
    if(controlKeyP->a.state)     cameraP->Strafe(moveSpeed);
    if(controlKeyP->s.state)     cameraP->Move(-moveSpeed);
    if(controlKeyP->d.state)     cameraP->Strafe(-moveSpeed);
    if(controlKeyP->lctrl.state) cameraP->Fly(-moveSpeed);
    if(controlKeyP->space.state) cameraP->Fly(moveSpeed);

    if(!cursorCentered) return;
    glutWarpPointer((glutGet(GLUT_WINDOW_WIDTH) / 2), (glutGet(GLUT_WINDOW_HEIGHT) / 2));
}
