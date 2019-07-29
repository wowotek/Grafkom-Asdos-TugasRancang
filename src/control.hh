#ifndef CONTROL_HH
#define CONTROL_HH

#include <vector>

#include "common.hh"
#include "camera.hh"

void InitControl(Camera *, ControlKey *, MousePos *);

void MouseButtonEventHandler(int, int, int, int);
void MouseDragEventHandler(int, int);
void MouseMoveEventHandler(int, int);

void KeyboardDownEventHandler(unsigned char, int, int);
void KeyboardUpEventHandler(unsigned char, int, int);
void KeyboardSpecialDownEventHandler(int, int, int);
void KeyboardSpecialUpEventHandler(int, int, int);

void ControlCallback();


#endif
