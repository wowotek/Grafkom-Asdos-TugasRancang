#include "furniture.hh"

unsigned int * fTex;

void
Furniture::InitFurnituresTexture(unsigned int * initTextures)
{
    fTex = initTextures;
}

void
Furniture::Chair(Coord3D pos, bool facing)
{
    if(facing){ // facing left
        // kaki
        glColor3ub(222, 174, 84);
        Box(Coord3D(0+pos.x, 0+pos.y, 0+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0.5+pos.x, 0+pos.y, 0+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0.5+pos.x, 0+pos.y, 0.4+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0+pos.x, 0+pos.y, 0.4+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        // duduk
        Box(Coord3D(0+pos.x, 0.5+pos.y, 0+pos.z), Coord3D(0.55, 0.07, 0.45), fTex[4]);
        // punggung
        Box(Coord3D(0+pos.x, 0.57+pos.y, 0.4+pos.z), Coord3D(0.05, 0.6, 0.05), fTex[4]);
        glColor3ub(176, 117, 7);
        Box(Coord3D(0.125+pos.x, 0.57+pos.y, 0.42+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        Box(Coord3D(0.25+pos.x, 0.57+pos.y, 0.42+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        Box(Coord3D(0.375+pos.x, 0.57+pos.y, 0.42+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        glColor3ub(222, 174, 84);
        Box(Coord3D(0.5+pos.x, 0.57+pos.y, 0.4+pos.z), Coord3D(0.05, 0.6, 0.05), fTex[4]);
        Box(Coord3D(0+pos.x, 1.17+pos.y, 0.4+pos.z), Coord3D(0.55, 0.05, 0.05), fTex[4]);
    } else { // Right
        glColor3ub(222, 174, 84);
        Box(Coord3D(0+pos.x, 0+pos.y, 0+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0.5+pos.x, 0+pos.y, 0+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0.5+pos.x, 0+pos.y, 0.4+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        Box(Coord3D(0+pos.x, 0+pos.y, 0.4+pos.z), Coord3D(0.05, 0.5, 0.05), fTex[4]);
        // duduk
        Box(Coord3D(0+pos.x, 0.5+pos.y, 0+pos.z), Coord3D(0.55, 0.07, 0.45), fTex[4]);
        // punggung
        glColor3ub(176, 117, 7);
        Box(Coord3D(0+pos.x, 0.57+pos.y, 0+pos.z), Coord3D(0.05, 0.6, 0.05), fTex[4]);
        Box(Coord3D(0.125+pos.x, 0.57+pos.y, 0+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        Box(Coord3D(0.25+pos.x, 0.57+pos.y, 0+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        Box(Coord3D(0.375+pos.x, 0.57+pos.y, 0+pos.z), Coord3D(0.05, 0.6, 0.03), fTex[4]);
        glColor3ub(222, 174, 84);
        Box(Coord3D(0.5+pos.x, 0.57+pos.y, 0+pos.z), Coord3D(0.05, 0.6, 0.05), fTex[4]);
        Box(Coord3D(0+pos.x, 1.17+pos.y, 0+pos.z), Coord3D(0.55, 0.05, 0.05), fTex[4]);
    }
}

void
Furniture::Couch(Coord3D pos, bool facing)
{
    if(facing){
        glColor3ub(123, 140, 150);
        Box(Coord3D(0+pos.x, 0+pos.y, 0+pos.z), Coord3D(1, 0.7, 0.125), fTex[5]);
        glColor3ub(161, 106, 19);
        Box(Coord3D(0.9+pos.x, 0+pos.y, 0.125+pos.z), Coord3D(0.1, 0.9, 0.675), fTex[6]);
        Box(Coord3D(0.1+pos.x, 0+pos.y, 0.125+pos.z), Coord3D(0.8, 0.2, 0.675), fTex[6]);
        Box(Coord3D(0+pos.x, 0.2+pos.y, 0.125+pos.z), Coord3D(0.9, 0.25, 0.675), fTex[6]);
        glColor3ub(123, 140, 150);
        Box(Coord3D(0+pos.x, 0+pos.y, 0.8+pos.z), Coord3D(1, 0.7, 0.125), fTex[5]);
    } else {
        glColor3ub(123, 140, 150);
        Box(Coord3D(0+pos.x, 0+pos.y, 0+pos.z), Coord3D(1, 0.7, 0.125), fTex[5]);
        glColor3ub(161, 106, 19);
        Box(Coord3D(0+pos.x, 0+pos.y, 0.125+pos.z), Coord3D(0.1, 0.9, 0.675), fTex[6]);
        Box(Coord3D(0.1+pos.x, 0+pos.y, 0.125+pos.z), Coord3D(0.8, 0.2, 0.675), fTex[6]);
        Box(Coord3D(0.1+pos.x, 0.2+pos.y, 0.125+pos.z), Coord3D(0.9, 0.25, 0.675), fTex[6]);
        glColor3ub(123, 140, 150);
        Box(Coord3D(0+pos.x, 0+pos.y, 0.8+pos.z), Coord3D(1, 0.7, 0.125), fTex[5]);
    }
}

void
Furniture::Bed(Coord3D pos, bool facing)
{
    if(facing){

    } else {

    }
}