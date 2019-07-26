#include <math.h>
#include <iostream>
#include <GL/glut.h>

#include "render.hh"
#include "structure.hh"


CameraData * cameraRendererP;
void (* controlCallback)();

void
InitRenderer(CameraData * initCamera, void (* cb)())
{
    cameraRendererP = initCamera;
    controlCallback = cb;
}

void
RenderDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    glLoadIdentity();
    glTranslatef(
        cameraRendererP->pos.x,
        cameraRendererP->pos.y,
        cameraRendererP->pos.z
    );
    glRotatef(0, 1, 1, 0.25);

    // floor
    glColor3f(0.5, 0.5, 0.5);
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

    Box(Coord3D(1, 1, 1), Coord3D(2, 2, 2));

    glMatrixMode(GL_PROJECTION);

    glutSwapBuffers();
}

void
BlitDisplay(int)
{
    (*controlCallback)();
    glutPostRedisplay();
    glutTimerFunc(16, BlitDisplay, 0);
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
        45.0f, (float)(newHeight) / (float)(newWidth), 1.0f, 1000.0f
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}