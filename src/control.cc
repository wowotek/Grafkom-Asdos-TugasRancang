#include <iostream>
#include <vector>
#include <algorithm>
#include <GL/glut.h>

#include "control.hh"

CameraData * cameraControlP;

void
InitControl(CameraData * initCamera){
    cameraControlP = initCamera;
}

void
MouseButtonEventHandler(int, int, int, int)
{

}

void
MouseDragEventHandler(int, int)
{

}

void
MouseMoveEventHandler(int, int)
{

}

void
KeyboardDownEventHandler(unsigned char key, int, int)
{
}

void
KeyboardUpEventHandler(unsigned char key, int, int)
{
}

float MOVE_SPEED = 0.01f;

void
KeyboardSpecialDownEventHandler(int key, int, int)
{
}

void
KeyboardSpecialUpEventHandler(int key, int, int)
{
}

void
ControlCallback()
{
}
