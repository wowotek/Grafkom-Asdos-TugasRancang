#ifndef STRUCTURE_HH
#define STRUCTURE_HH

#include <GL/glut.h>

#include "common.hh"

struct CubeFaceColor{
    Color3f front   = Color3f(1, 0, 0);
    Color3f left    = Color3f(0, 1, 0);
    Color3f top     = Color3f(1, 1, 0);
    Color3f right   = Color3f(0, 0, 1);
    Color3f bottom  = Color3f(1, 0, 1);
    Color3f back    = Color3f(1, 1, 1);
};

void Box(Coord3D, Coord3D);
void Box(Coord3D, Coord3D, CubeFaceColor);

#endif