#include "structure.hh"

unsigned int * sTexs;

void
Structures::InitStructureTexture(unsigned int * initTex)
{
    sTexs = initTex;
}

void
Structures::SkyBox(Coord3D pos)
{
    TextureID back = sTexs[11];
    TextureID front = sTexs[12];
    TextureID left = sTexs[13];
    TextureID right = sTexs[14];
    TextureID top = sTexs[15];

    float x = pos.x - 250;
    float y = pos.y - 250;
    float z = pos.z - 250;

    float sx = 500;
    float sy = 500;
    float sz = 500;

    Coord3D p(x, y, z);

    Box(Coord3D(x, y, z), Coord3D(500, 500, 500));

    // Depan
    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(up3add(p, 0, 0, 0));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, sx, 0, 0));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, sx, sy, 0));
        glTexCoord2f(0, 1); glVertex3f(up3add(p, 0, sy, 0));
    glEnd();

    // Kiri
    glBindTexture(GL_TEXTURE_2D, left);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(up3add(p, 0, 0, 0));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, 0, 0, sz));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, 0, sy, sz));
        glTexCoord2f(0, 1); glVertex3f(up3add(p, 0, sy, 0));
    glEnd();

    // Atas
    glBindTexture(GL_TEXTURE_2D, top);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(up3add(p, 0, sy, 0));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, sx, sy, 0));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, sx, sy, sz));
        glTexCoord2f(0, 1); glVertex3f(up3add(p, 0, sy, sz));
    glEnd();

    // Kanan
    glBindTexture(GL_TEXTURE_2D, right);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(up3add(p, sx, sy, 0));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, sx, sy, sz));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, sx, 0, sz));
        glTexCoord2f(0, 0); glVertex3f(up3add(p, sx, 0, 0));
    glEnd();

    // Bawah
    glBindTexture(GL_TEXTURE_2D, 0);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(up3add(p, sx, 0, 0));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, 0, 0, 0));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, 0, 0, sz));
        glTexCoord2f(0, 1); glVertex3f(up3add(p, sx, 0, sz));
    glEnd();

    // Belakang
    glBindTexture(GL_TEXTURE_2D, back);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(up3add(p, 0, sy, sz));
        glTexCoord2f(1, 1); glVertex3f(up3add(p, sx, sy, sz));
        glTexCoord2f(1, 0); glVertex3f(up3add(p, sx, 0, sz));
        glTexCoord2f(0, 0); glVertex3f(up3add(p, 0, 0, sz));
    glEnd();
}

void
Structures::FullHouse(Coord3D pos)
{
    Roof(Coord3D(up3add(pos, 0, 4.85, -1.88)));
    House(Coord3D(up3add(pos, 0, 0, 0)));

    float x = pos.x;
    float y = pos.y;
    float z = pos.z;
    glColor3ub(112, 62, 11);
    glBindTexture(GL_TEXTURE_2D, sTexs[3]);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(x   , y+5.6, z);
        glTexCoord2f(1, 0); glVertex3f(x   , y+5.6, z+10.25);
        glTexCoord2f(0.5, 1); glVertex3f(x   , y+7.8, z+5.125);
    glEnd();
    glColor3ub(112, 62, 11);
    glBindTexture(GL_TEXTURE_2D, sTexs[3]);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(x+0.1   , y+5.6, z);
        glTexCoord2f(1, 0); glVertex3f(x+0.1  , y+5.6, z+10.25);
        glTexCoord2f(0.5, 1); glVertex3f(x+0.1   , y+7.8, z+5.125);
    glEnd();

    glColor3ub(112, 62, 11);
    glBindTexture(GL_TEXTURE_2D, sTexs[3]);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(x+15.15  , y+5.6, z);
        glTexCoord2f(1, 0); glVertex3f(x+15.15  , y+5.6, z+10.25);
        glTexCoord2f(0.5, 1); glVertex3f(x+15.15, y+7.8, z+5.125);
    glEnd();
    glColor3ub(112, 62, 11);
    glBindTexture(GL_TEXTURE_2D, sTexs[3]);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(x+15.25  , y+5.6, z);
        glTexCoord2f(1, 0); glVertex3f(x+15.25  , y+5.6, z+10.25);
        glTexCoord2f(0.5, 1); glVertex3f(x+15.25, y+7.8, z+5.125);
    glEnd();
}

void
Structures::Roof(Coord3D pos)
{    
    float x = pos.x;
    float y = pos.y;
    float z = pos.z;

    glColor3ub(112, 62, 11);
    // Atap Kiri Atas
    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z);
        glTexCoord2f(0, 1); glVertex3f(x+16, y    , z);
        glTexCoord2f(1, 1); glVertex3f(x+19, y+3  , z+7);
        glTexCoord2f(1, 0); glVertex3f(x-3 , y+3  , z+7);
    glEnd();

    // Atap Kanan Atas
    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+3  , z+7);
        glTexCoord2f(0, 1); glVertex3f(x-3 , y+3  , z+7);
        glTexCoord2f(1, 1); glVertex3f(x   , y    , z+14);
        glTexCoord2f(1, 0); glVertex3f(x+16, y    , z+14);
    glEnd();

    // Atap Kiri Bawah
    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+0.1);
        glTexCoord2f(0, 1); glVertex3f(x+16, y    , z+0.1);
        glTexCoord2f(1, 1); glVertex3f(x+19, y+2.9, z+7);
        glTexCoord2f(1, 0); glVertex3f(x-3 , y+2.9, z+7);
    glEnd();

    // Atap Kanan Bawah
    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+2.9, z+7);
        glTexCoord2f(0, 1); glVertex3f(x-3 , y+2.9, z+7);
        glTexCoord2f(1, 1); glVertex3f(x   , y    , z+13.9);
        glTexCoord2f(1, 0); glVertex3f(x+16, y    , z+13.9);
    glEnd();

    // Filler
    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+0.1);
        glTexCoord2f(0, 0); glVertex3f(x-3 , y+2.9, z+7);
        glTexCoord2f(0, 0); glVertex3f(x-3 , y+3, z+7);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x-3 , y+2.9, z+7);
        glTexCoord2f(0, 0); glVertex3f(x-3 , y+3  , z+7);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+13.9);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+14);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+0.1);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+2.9, z+7);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+3  , z+7);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+2.9, z+7);
        glTexCoord2f(0, 0); glVertex3f(x+19, y+3  , z+7);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+13.9);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+14);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+0.1);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+0.1);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, sTexs[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+13.9);
        glTexCoord2f(0, 0); glVertex3f(x   , y    , z+14);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+14);
        glTexCoord2f(0, 0); glVertex3f(x+16, y    , z+13.9);
    glEnd();
}

void
Structures::House(Coord3D pos)
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
    Box(Coord3D(-3+pos.x, 2+pos.y, 4+pos.z), Coord3D(3, 0.1, 2.25), sTexs[4]);

    // Tangga Depan Kiri
    for(float i=0; i < 2; i += 0.2){
        Box(Coord3D(-3+pos.x, i+pos.y, i+2+pos.z), Coord3D(1.5, 0.1, 0.4), sTexs[1]);
    }
    // Tangga Depan Kanan
    for(float i=0; i < 2; i += 0.2){
        Box(Coord3D(-3+pos.x, i+pos.y, -i+7.85+pos.z), Coord3D(1.5, 0.1, 0.4), sTexs[1]);
    }
}