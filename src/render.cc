#include <math.h>
#include <iostream>
#include <GL/glut.h>

#include "render.hh"
#include "structure.hh"

Camera * cameraRendererP;
void (* controlCallback)();

GLuint textures[2];

void
InitRenderer(Camera * initCamera, void (* cb)())
{
    LoadTexture(textures[0], "./data/textures/grass1.bmp");
    LoadTexture(textures[1], "data/textures/hardwood.bmp");

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
    glColor3f(1, 1, 1);
    for(int x = -100; x < 100; x++)
    {
        for(int z = -100; z < 100; z++)
        {   
            glBegin(GL_QUADS);
                glBindTexture(GL_TEXTURE_2D, textures[0]);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0+x, 0, 0+z);
                glTexCoord2f(0.0f, 1.0f); glVertex3f(0+x, 0, 1+z);
                glTexCoord2f(1.0f, 1.0f); glVertex3f(1+x, 0, 1+z);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(1+x, 0, 0+z);
                glBindTexture(GL_TEXTURE_2D, 0);
            glEnd();
        }
    }
}

float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
float mat_shininess[] = { 50.0 };
float light_position[] = { 5.0, 5.0, 5.0, 0.0 };

float ambient[] = {0.0, 1.0, 1.0, 1.0};

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

    // Foundation / Raiser
    for(float i=0; i<20; i+= 5){
        Box(Coord3D(0.05+i, 0.5, 0),   Coord3D(0.15, 1.5, 0.15), textures[1]);
            Box(Coord3D(-0.125+i, 0, -0.125),   Coord3D(0.4, 0.5, 0.4));
        Box(Coord3D(0.05+i, 0.5, 4.1), Coord3D(0.15, 1.5, 0.15));
            Box(Coord3D(-0.125+i, 0, 3.975),   Coord3D(0.4, 0.5, 0.4));
        Box(Coord3D(0.05+i, 0.5, 6),   Coord3D(0.15, 1.5, 0.15));
            Box(Coord3D(-0.125+i, 0, 5.875),   Coord3D(0.4, 0.5, 0.4));
        Box(Coord3D(0.05+i, 0.5, 10.1),Coord3D(0.15, 1.5, 0.15));
            Box(Coord3D(-0.125+i, 0, 9.975),   Coord3D(0.4, 0.5, 0.4));
    }

    // Floor Base
    Box(Coord3D(0, 2, 0), Coord3D(15.25, 0.1, 10.25));
    // Left
    Box(Coord3D(0, 2.1, 0), Coord3D(15.25, 3.5, 0.1));
    // Right
    Box(Coord3D(0, 2.1, 10.15), Coord3D(15.25, 3.5, 0.1));
    // Back
    Box(Coord3D(15.15, 2.1, 0.1), Coord3D(0.1, 3.5, 10.05));
    // Front Left
    Box(Coord3D(0, 2.1, 0.1), Coord3D(0.1, 3.5, 4.15));
    // Front Right
    Box(Coord3D(0, 2.1, 6), Coord3D(0.1, 3.5, 4.15));
    // Front Top
    Box(Coord3D(0, 4.1, 4.25), Coord3D(0.1, 1.5, 1.75));

    glPopMatrix();

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