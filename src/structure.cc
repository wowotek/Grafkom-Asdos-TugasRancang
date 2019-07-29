#include "structure.hh"

GLenum RENDER_MODE = GL_QUADS;

void
Box(Coord3D pos, Coord3D size)
{
    CubeFaceColor cubeFaceColor;
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;

    // Front
    glColor3f(up3(cubeFaceColor.front));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();

    // Kiri
    glColor3f(up3(cubeFaceColor.left));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Atas
    glColor3f(up3(cubeFaceColor.top));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
    glEnd();

    // Kanan
    glColor3f(up3(cubeFaceColor.right));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));
    glEnd();

    // Bawah
    glColor3f(up3(cubeFaceColor.bottom));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
    glEnd();

    // Belakang
    glColor3f(up3(cubeFaceColor.back));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();
}

void
Box(Coord3D pos, Coord3D size, CubeFaceColor * cubeFaceColor)
{
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;

    // Depan
    glColor3f(up3(cubeFaceColor->front));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Kiri
    glColor3f(up3(cubeFaceColor->left));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Atas
    glColor3f(up3(cubeFaceColor->top));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
    glEnd();

    // Kanan
    glColor3f(up3(cubeFaceColor->right));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));
    glEnd();

    // Bawah
    glColor3f(up3(cubeFaceColor->bottom));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
    glEnd();

    // Belakang
    glColor3f(up3(cubeFaceColor->back));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();
}

void
Box(Coord3D pos, Coord3D size, CubeTexture * cubeTexture)
{
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;

    // Depan
    glBindTexture(GL_TEXTURE_2D, cubeTexture->front.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Kiri
    glBindTexture(GL_TEXTURE_2D, cubeTexture->left.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Atas
    glBindTexture(GL_TEXTURE_2D, cubeTexture->top.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
    glEnd();

    // Kanan
    glBindTexture(GL_TEXTURE_2D, cubeTexture->right.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));
    glEnd();

    // Bawah
    glBindTexture(GL_TEXTURE_2D, cubeTexture->bottom.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
    glEnd();

    // Belakang
    glBindTexture(GL_TEXTURE_2D, cubeTexture->back.GetTexture());
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();
}

void
Box(Coord3D pos, Coord3D size, CubeTexture * cubeTexture, CubeFaceColor * cubeFaceColor)
{
    float sx = size.x;
    float sy = size.y;
    float sz = size.z;
    
    // Depan
    glBindTexture(GL_TEXTURE_2D, cubeTexture->front.GetTexture());
    glColor3f(up3(cubeFaceColor->front));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Kiri
    glBindTexture(GL_TEXTURE_2D, cubeTexture->left.GetTexture());
    glColor3f(up3(cubeFaceColor->left));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, 0, sy, 0));
    glEnd();

    // Atas
    glBindTexture(GL_TEXTURE_2D, cubeTexture->top.GetTexture());
    glColor3f(up3(cubeFaceColor->top));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, 0));
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, 0, sy, sz));
    glEnd();

    // Kanan
    glBindTexture(GL_TEXTURE_2D, cubeTexture->right.GetTexture());
    glColor3f(up3(cubeFaceColor->right));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, sy, 0));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, sx, 0, 0));
    glEnd();

    // Bawah
    glBindTexture(GL_TEXTURE_2D, cubeTexture->bottom.GetTexture());
    glColor3f(up3(cubeFaceColor->bottom));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, sx, 0, 0));
        glVertex3f(up3add(pos, 0, 0, 0));
        glVertex3f(up3add(pos, 0, 0, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
    glEnd();

    // Belakang
    glBindTexture(GL_TEXTURE_2D, cubeTexture->back.GetTexture());
    glColor3f(up3(cubeFaceColor->back));
    glBegin(RENDER_MODE);
        glVertex3f(up3add(pos, 0, sy, sz));
        glVertex3f(up3add(pos, sx, sy, sz));
        glVertex3f(up3add(pos, sx, 0, sz));
        glVertex3f(up3add(pos, 0, 0, sz));
    glEnd();
}