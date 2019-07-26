#include "structure.hh"

void
Box(Coord3D pos, Coord3D size)
{
    CubeFaceColor cubeFaceColor;
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;

    glBegin(GL_QUADS);
        // Depan
        glColor3f(up3(cubeFaceColor.front));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));

        // Kiri
        glColor3f(up3(cubeFaceColor.left));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));

        // Atas
        glColor3f(up3(cubeFaceColor.top));
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));

        // Kanan
        glColor3f(up3(cubeFaceColor.right));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));

        // Bawah
        glColor3f(up3(cubeFaceColor.bottom));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));

        // Belakang
        glColor3f(up3(cubeFaceColor.back));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();
}

void
Box(Coord3D pos, Coord3D size, CubeFaceColor cubeFaceColor)
{
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;

    glBegin(GL_QUADS);
        // Depan
        glColor3f(up3(cubeFaceColor.front));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));

        // Kiri
        glColor3f(up3(cubeFaceColor.left));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));

        // Atas
        glColor3f(up3(cubeFaceColor.top));
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));

        // Kanan
        glColor3f(up3(cubeFaceColor.right));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));

        // Bawah
        glColor3f(up3(cubeFaceColor.bottom));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));

        // Belakang
        glColor3f(up3(cubeFaceColor.back));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();
}