#include "structure.hh"

unsigned int * sTexs;

void
Structures::InitStructureTexture(unsigned int * initTex)
{
    sTexs = initTex;
}

void
Structures::DrawHouse()
{
    // Foundation / Raiser
    glColor3f(1, 1, 1);
    for(float i=0; i<20; i+= 5){
        Box(Coord3D(0.05+i, 0.5, 0),   Coord3D(0.15, 1.5, 0.15), sTexs[1]);
            Box(Coord3D(-0.07+i, 0, -0.125),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);
        Box(Coord3D(0.05+i, 0.5, 4.1), Coord3D(0.15, 1.5, 0.15), sTexs[1]);
            Box(Coord3D(-0.07+i, 0, 3.975),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);
        Box(Coord3D(0.05+i, 0.5, 6),   Coord3D(0.15, 1.5, 0.15), sTexs[1]);
            Box(Coord3D(-0.07+i, 0, 5.875),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);
        Box(Coord3D(0.05+i, 0.5, 10.1),Coord3D(0.15, 1.5, 0.15), sTexs[1]);
            Box(Coord3D(-0.07+i, 0, 9.975),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);
    }
    // Floor Base
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 2, 0), Coord3D(15.25, 0.1, 10.25), sTexs[1]);

    // Left
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 2.1, 0), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(6.5, 2.1, 0), Coord3D(8.75, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(0, 2.1, 0), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    // --- Window
    Box(Coord3D(3.5, 4.6, 0), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(3.5, 2.1, 0), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(4.85, 3.1, 0), Coord3D(0.25, 1.5, 0.1), sTexs[1]);

    // Right
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 2.1, 10.15), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(6.5, 2.1, 10.15), Coord3D(8.75, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(0, 2.1, 10.15), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    // --- Window
    Box(Coord3D(3.5, 4.6, 10.15), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(3.5, 2.1, 10.15), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(4.85, 3.1, 10.15), Coord3D(0.25, 1.5, 0.1), sTexs[1]);

    // Back
    glColor3ub(112, 84, 17);
    Box(Coord3D(15.15, 2.1, 0.1), Coord3D(0.1, 3.5, 10.05), sTexs[3]);

    // Front Left
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 2.1, 0.1), Coord3D(0.1, 2.5, 4.15), sTexs[3]);
    Box(Coord3D(0, 5, 0.1), Coord3D(0.1, 0.6, 4.15), sTexs[3]);
    Box(Coord3D(0, 4.6, 0.1), Coord3D(0.1, 0.4, 1), sTexs[3]);
    Box(Coord3D(0, 4.6, 3), Coord3D(0.1, 0.4, 1.25), sTexs[3]);

    // Front Right
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 2.1, 6), Coord3D(0.1, 2.5, 4.15), sTexs[3]);
    Box(Coord3D(0, 5, 6), Coord3D(0.1, 0.6, 4.15), sTexs[3]);
    Box(Coord3D(0, 4.6, 6), Coord3D(0.1, 0.4, 1), sTexs[3]);
    Box(Coord3D(0, 4.6, 8.9), Coord3D(0.1, 0.4, 1.25), sTexs[3]);

    // Front Top
    glColor3ub(112, 84, 17);
    Box(Coord3D(0, 4.1, 4.25), Coord3D(0.1, 1.5, 1.75), sTexs[3]);

    // Ruang Tengah
    glColor3ub(112, 84, 17);
    Box(Coord3D(9, 2.1, 0.1), Coord3D(0.1, 1.25, 5), sTexs[3]);
    Box(Coord3D(9, 2.1, 5.1), Coord3D(0.1, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(10.6, 2.1, 5.1), Coord3D(0.1, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(10.7, 2.1, 5.1), Coord3D(4.45, 1.25, 0.1), sTexs[3]);
}