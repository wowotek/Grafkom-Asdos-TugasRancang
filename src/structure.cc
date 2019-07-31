#include "structure.hh"

unsigned int * sTexs;

void
Structures::InitStructureTexture(unsigned int * initTex)
{
    sTexs = initTex;
}

void
Structures::DrawHouse(Coord3D pos)
{
    // Foundation / Raiser
    glColor3f(1, 1, 1);
    for(float i=0+pos.x; i<20+pos.x; i+= 5){
        Box(Coord3D(0.05+i, 0.5+pos.y, 0+pos.z),   Coord3D(0.15, 1.5, 0.15), sTexs[1]);
        Box(Coord3D(-0.07+i, 0+pos.y, -0.125+pos.z),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);

        Box(Coord3D(0.05+i, 0.5+pos.y, 4.1+pos.z), Coord3D(0.15, 1.5, 0.15), sTexs[1]);
        Box(Coord3D(-0.07+i, 0+pos.y, 3.975+pos.z),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);

        Box(Coord3D(0.05+i, 0.5+pos.y, 6+pos.z),   Coord3D(0.15, 1.5, 0.15), sTexs[1]);
        Box(Coord3D(-0.07+i, 0+pos.y, 5.875+pos.z),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);

        Box(Coord3D(0.05+i, 0.5+pos.y, 10.1+pos.z),Coord3D(0.15, 1.5, 0.15), sTexs[1]);
        Box(Coord3D(-0.07+i, 0+pos.y, 9.975+pos.z),   Coord3D(0.4, 0.5, 0.4), sTexs[2]);
    }
    // Floor Base
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 2+pos.y, 0+pos.z), Coord3D(15.25, 0.1, 10.25), sTexs[1]);

    // Left
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 0+pos.z), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(6.5+pos.x, 2.1+pos.y, 0+pos.z), Coord3D(8.75, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 0+pos.z), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    // --- Window
    Box(Coord3D(3.5+pos.x, 4.6+pos.y, 0+pos.z), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(3.5+pos.x, 2.1+pos.y, 0+pos.z), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(4.85+pos.x, 3.1+pos.y, 0+pos.z), Coord3D(0.25, 1.5, 0.1), sTexs[1]);

    // Right
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 10.15+pos.z), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(6.5+pos.x, 2.1+pos.y, 10.15+pos.z), Coord3D(8.75, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 10.15+pos.z), Coord3D(3.5, 3.5, 0.1), sTexs[3]);
    // --- Window
    Box(Coord3D(3.5+pos.x, 4.6+pos.y, 10.15+pos.z), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(3.5+pos.x, 2.1+pos.y, 10.15+pos.z), Coord3D(3, 1, 0.1), sTexs[1]);
    Box(Coord3D(4.85+pos.x, 3.1+pos.y, 10.15+pos.z), Coord3D(0.25, 1.5, 0.1), sTexs[1]);

    // Back
    glColor3ub(112, 84, 17);
    Box(Coord3D(15.15+pos.x, 2.1+pos.y, 0.1+pos.z), Coord3D(0.1, 3.5, 10.05), sTexs[3]);

    // Front Left
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 0.1+pos.z), Coord3D(0.1, 2.5, 4.15), sTexs[3]);
    Box(Coord3D(0+pos.x, 5+pos.y, 0.1+pos.z), Coord3D(0.1, 0.6, 4.15), sTexs[3]);
    Box(Coord3D(0+pos.x, 4.6+pos.y, 0.1+pos.z), Coord3D(0.1, 0.4, 1), sTexs[3]);
    Box(Coord3D(0+pos.x, 4.6+pos.y, 3+pos.z), Coord3D(0.1, 0.4, 1.25), sTexs[3]);

    // Front Right
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 2.1+pos.y, 6+pos.z), Coord3D(0.1, 2.5, 4.15), sTexs[3]);
    Box(Coord3D(0+pos.x, 5+pos.y, 6+pos.z), Coord3D(0.1, 0.6, 4.15), sTexs[3]);
    Box(Coord3D(0+pos.x, 4.6+pos.y, 6+pos.z), Coord3D(0.1, 0.4, 1), sTexs[3]);
    Box(Coord3D(0+pos.x, 4.6+pos.y, 8.9+pos.z), Coord3D(0.1, 0.4, 1.25), sTexs[3]);

    // Front Top
    glColor3ub(112, 84, 17);
    Box(Coord3D(0+pos.x, 4.1+pos.y, 4.25+pos.z), Coord3D(0.1, 1.5, 1.75), sTexs[3]);

    // Ruang Tengah
    glColor3ub(112, 84, 17);
    Box(Coord3D(9+pos.x, 2.1+pos.y, 0.1+pos.z), Coord3D(0.1, 1.25, 5), sTexs[3]);
    Box(Coord3D(9+pos.x, 2.1+pos.y, 5.1+pos.z), Coord3D(0.1, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(10.6+pos.x, 2.1+pos.y, 5.1+pos.z), Coord3D(0.1, 3.5, 0.1), sTexs[3]);
    Box(Coord3D(10.7+pos.x, 2.1+pos.y, 5.1+pos.z), Coord3D(4.45, 1.25, 0.1), sTexs[3]);

    // Teras Depan
    Box(Coord3D(-3+pos.x, 2+pos.y, 4+pos.z), Coord3D(3, 0.1, 2.25));

    // Tangga Depan Kiri
    for(float i=0; i < 2; i += 0.2){
        Box(Coord3D(-3+pos.x, i+pos.y, i+2+pos.z), Coord3D(1.5, 0.1, 0.4));
    }
    // Tangga Depan Kanan
    for(float i=0; i < 2; i += 0.2){
        Box(Coord3D(-3+pos.x, i+pos.y, -i+7.85+pos.z), Coord3D(1.5, 0.1, 0.4));
    }
}