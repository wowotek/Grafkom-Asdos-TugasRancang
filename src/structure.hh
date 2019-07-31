#ifndef STRUCTURE_HH
#define STRUCTURE_HH

#include <GL/glut.h>

#include "common.hh"
#include "texture.hh"
#include "solid.hh"

namespace Structures{
    void InitStructureTexture(unsigned int *);
    void House(Coord3D);
    void Roof(Coord3D);
    void FullHouse(Coord3D);
    void SkyBox(Coord3D);
}

#endif