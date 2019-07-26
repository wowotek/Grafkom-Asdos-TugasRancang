#include <iostream>
#include <vector>
#include <algorithm>
#include <GL/glut.h>

#include "control.hh"

CameraData * cameraControlP;
std::vector<unsigned char> * keyPressesControlP;
std::vector<int> * specKeyPressesControlP;

void
InitControl(
    CameraData * initCamera,
    std::vector<unsigned char> * initKeyPresses,
    std::vector<int> * initSpecKeyPresses)
{
    cameraControlP = initCamera;
    keyPressesControlP = initKeyPresses;
    specKeyPressesControlP = initSpecKeyPresses;
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
    for(unsigned int i=0; i<specKeyPressesControlP->size(); i++){
        // if(specKeyPressesControlP->at(i) == GLUT_KEY_){
        //     cameraControlP->pos.y += MOVE_SPEED;
        // }

        if(specKeyPressesControlP->at(i) == 114){
            cameraControlP->pos.y += MOVE_SPEED;
        }
    }

    for(unsigned int j=0; j<keyPressesControlP->size(); j++){
        if(keyPressesControlP->at(j) == 'w'){
            cameraControlP->pos.z += MOVE_SPEED;
        }

        if(keyPressesControlP->at(j) == 'a'){
            cameraControlP->pos.x += MOVE_SPEED;
        }

        if(keyPressesControlP->at(j) == 's'){
            cameraControlP->pos.z -= MOVE_SPEED;
        }

        if(keyPressesControlP->at(j) == 'd'){
            cameraControlP->pos.x -= MOVE_SPEED;
        }

        if(keyPressesControlP->at(j) == ' '){
            cameraControlP->pos.y -= MOVE_SPEED;
        }
    }
}