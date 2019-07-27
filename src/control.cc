#include <iostream>
#include <vector>
#include <algorithm>
#include <GL/glut.h>

#include "control.hh"
#include "keyboard.hh"

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

Keyboard keyboard;

void
KeyboardDownEventHandler(unsigned char key, int, int)
{
    if(key == 'w' || key == 'W')
        keyboard.setKeyPressed(Keyboard::Key::W, true);
    if(key == 'a' || key == 'A')
        keyboard.setKeyPressed(Keyboard::Key::A, true);
    if(key == 's' || key == 'S')
        keyboard.setKeyPressed(Keyboard::Key::S, true);
    if(key == 'd' || key == 'D')
        keyboard.setKeyPressed(Keyboard::Key::D, true);
}

void
KeyboardUpEventHandler(unsigned char key, int, int)
{
    if(key == 'w' || key == 'W')
        keyboard.setKeyPressed(Keyboard::Key::W, false);
    if(key == 'a' || key == 'A')
        keyboard.setKeyPressed(Keyboard::Key::A, false);
    if(key == 's' || key == 'S')
        keyboard.setKeyPressed(Keyboard::Key::S, false);
    if(key == 'd' || key == 'D')
        keyboard.setKeyPressed(Keyboard::Key::D, false);
}

float MOVE_SPEED = 0.01f;

void
KeyboardSpecialDownEventHandler(int key, int, int)
{
    if(key==112) keyboard.setKeyPressed(Keyboard::Key::LEFT_SHIFT, true);
    if(key==114) keyboard.setKeyPressed(Keyboard::Key::LEFT_CONTROL, true);
}

void
KeyboardSpecialUpEventHandler(int key, int, int)
{
    if(key==112) keyboard.setKeyPressed(Keyboard::Key::LEFT_SHIFT, false);
    if(key==114) keyboard.setKeyPressed(Keyboard::Key::LEFT_CONTROL, false);
}

void
ControlCallback()
{
    if(keyboard.getKeyPressed(Keyboard::Key::LEFT_CONTROL)){
        cameraControlP->pos.y += MOVE_SPEED;
    }
        
    if(keyboard.getKeyPressed(Keyboard::Key::W)){
        cameraControlP->pos.z += MOVE_SPEED;
    }

    if(keyboard.getKeyPressed(Keyboard::Key::A)){
        cameraControlP->pos.x += MOVE_SPEED;
    }

    if(keyboard.getKeyPressed(Keyboard::Key::S)){
        cameraControlP->pos.z -= MOVE_SPEED;
    }

    if(keyboard.getKeyPressed(Keyboard::Key::D)){
        cameraControlP->pos.x -= MOVE_SPEED;
    }

    if(keyboard.getKeyPressed(Keyboard::Key::SPACE)){
        cameraControlP->pos.y -= MOVE_SPEED;
    }
}