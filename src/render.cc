#include <math.h>
#include <iostream>
#include <GL/glut.h>

#include "render.hh"
#include "structure.hh"


Camera * cameraRendererP;
void (* controlCallback)();

void
InitRenderer(Camera * initCamera, void (* cb)())
{
    cameraRendererP = initCamera;
    controlCallback = cb;
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
    glColor3f(0.2, 0.2, 0.2);
    for(int x = -100; x < 100; x++)
    {
        for(int z = -100; z < 100; z++)
        {
            glBegin(GL_LINE_LOOP);
                glVertex3f(0+x, 0, 0+z);
                glVertex3f(0+x, 0, 1+z);
                glVertex3f(1+x, 0, 1+z);
                glVertex3f(1+x, 0, 0+z);
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
    DrawFloorGrid();
    DrawAxisLine();

    // Foundation / Raiser
    Box(Coord3D(0, 0, 0), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(0, 0, 4), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(0, 0, 6), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(0, 0, 10), Coord3D(0.25, 2, 0.25));

    Box(Coord3D(5, 0, 0), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(5, 0, 4), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(5, 0, 6), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(5, 0, 10), Coord3D(0.25, 2, 0.25));

    Box(Coord3D(10, 0, 0), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(10, 0, 4), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(10, 0, 6), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(10, 0, 10), Coord3D(0.25, 2, 0.25));

    Box(Coord3D(15, 0, 0), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(15, 0, 4), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(15, 0, 6), Coord3D(0.25, 2, 0.25));
    Box(Coord3D(15, 0, 10), Coord3D(0.25, 2, 0.25));

    // Floor Base
    Box(Coord3D(0, 2, 0), Coord3D(15.25, 0.1, 10.25));

    // Left
    Box(Coord3D(0, 2.1, 0), Coord3D(15.25, 3.5, 0.1));

    // Left
    Box(Coord3D(0, 2.1, 10.15), Coord3D(15.25, 3.5, 0.1));

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
        45.0f, (float)(newHeight) / (float)(newWidth), 0.0005f, 1000.0f
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}