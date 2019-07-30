#ifndef FURNITURE_HH
#define FURNITURE_HH

#include "structure.hh"
#include "common.hh"

namespace Furniture{
    void InitFurnituresTexture(unsigned int *);
    void Chair(Coord3D, bool);
    void Couch(Coord3D, bool);
    void Bed(Coord3D, bool);
}

#endif