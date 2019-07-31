#include <math.h>
#include <iostream>
#include <GL/glut.h>

#include "render.hh"
#include "structure.hh"
#include "furniture.hh"

Camera * cameraRendererP;
void (* controlCallback)();
GLuint * texs;

void
InitRenderer(Camera * initCamera, unsigned int * initTexture, void (* cb)())
{
    texs = initTexture;
    Furniture::InitFurnituresTexture(texs);
    Structures::InitStructureTexture(texs);

    cameraRendererP = initCamera;
    controlCallback = cb;
}

inline void
DrawSkyBoxes()
{

}

inline void
DrawAxisLine()
{
    // X LINE
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(-100, 0, 0);
        glVertex3f(100, 0, 0);
    glEnd();

    // Y LINE
    glLineWidth(3);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0, -100, 0);
        glVertex3f(0, 100, 0);
    glEnd();

    // Z LINE
    glLineWidth(3);
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3f(0, 0, -100);
        glVertex3f(0, 0, 100);
    glEnd();
}

inline void
DrawFloorGrid()
{
    // Floor Grid
    glLineWidth(0.1);
    glColor3f(1, 1, 1);
    for(int x = -100; x < 100; x++)
    {
        for(int z = -100; z < 100; z++)
        {
            glBindTexture(GL_TEXTURE_2D, texs[0]);
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0); glVertex3f(0+x, 0, 0+z);
                glTexCoord2f(0, 1); glVertex3f(0+x, 0, 1+z);
                glTexCoord2f(1, 1); glVertex3f(1+x, 0, 1+z);
                glTexCoord2f(1, 0); glVertex3f(1+x, 0, 0+z);
            glEnd();
        }
    }
}

void
RenderDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    glLoadIdentity();
    cameraRendererP->Refresh();
    glPushMatrix();
    DrawFloorGrid();
    DrawAxisLine();
    glPopMatrix();

    glPushMatrix();
    Furniture::NamePlate(Coord3D(0, 0, 0), true);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glutSwapBuffers();
}

void
BlitDisplay(int)
{
    (*controlCallback)();

    glutPostRedisplay();
    glutTimerFunc(1000.0/120.0, BlitDisplay, 0);
}

void
ReshapeDisplay(int newHeight, int newWidth)
{
    // if (newHeight == 0) newHeight = 1;

    // float aspect = (float)newWidth / (float)newHeight;
    glViewport(0, 0, newHeight, newWidth);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0f, (float)(newHeight) / (float)(newWidth), 0.01f, 1000.0f
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}