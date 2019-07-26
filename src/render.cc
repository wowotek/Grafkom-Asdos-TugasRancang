#include <math.h>
#include <iostream>
#include <GL/glut.h>

#include "render.hh"
#include "structure.hh"

float angle = 0;
float zoom = 0;

void
RenderDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    glLoadIdentity();
    glTranslatef(0, 0, -10);
    // glRotatef(angle, 1, 1, 0.25);
    
    Box(Coord3D(0, 0, 0), Coord3D(2, 20, 2));
    // glBegin(GL_QUADS);
    //     glColor3f(1, 0, 0);
    //     glVertex3f( 1.0f, 1.0f, -1.0f);
    //     glVertex3f(-1.0f, 1.0f, -1.0f);
    //     glVertex3f(-1.0f, 1.0f,  1.0f);
    //     glVertex3f( 1.0f, 1.0f,  1.0f);

    //     glColor3f(0, 1, 0);
    //     glVertex3f( 1.0f, -1.0f,  1.0f);
    //     glVertex3f(-1.0f, -1.0f,  1.0f);
    //     glVertex3f(-1.0f, -1.0f, -1.0f);
    //     glVertex3f( 1.0f, -1.0f, -1.0f);

    //     glColor3f(1, 1, 0);
    //     glVertex3f( 1.0f,  1.0f, 1.0f);
    //     glVertex3f(-1.0f,  1.0f, 1.0f);
    //     glVertex3f(-1.0f, -1.0f, 1.0f);
    //     glVertex3f( 1.0f, -1.0f, 1.0f);

    //     glColor3f(0, 0, 1);
    //     glVertex3f( 1.0f, -1.0f, -1.0f);
    //     glVertex3f(-1.0f, -1.0f, -1.0f);
    //     glVertex3f(-1.0f,  1.0f, -1.0f);
    //     glVertex3f( 1.0f,  1.0f, -1.0f);

    //     glColor3f(1, 0, 1);
    //     glVertex3f(-1.0f,  1.0f,  1.0f);
    //     glVertex3f(-1.0f,  1.0f, -1.0f);
    //     glVertex3f(-1.0f, -1.0f, -1.0f);
    //     glVertex3f(-1.0f, -1.0f,  1.0f);

    //     glColor3f(0, 1, 1);
    //     glVertex3f(1.0f,  1.0f, -1.0f);
    //     glVertex3f(1.0f,  1.0f,  1.0f);
    //     glVertex3f(1.0f, -1.0f,  1.0f);
    //     glVertex3f(1.0f, -1.0f, -1.0f);
    // glEnd();

    glutSwapBuffers();
}

void
BlitDisplay(int)
{
    angle+= 1;
    zoom = (((sin((M_PI * (angle/360))) / 2) + 0.5) * -10) - 5;

    std::cerr << angle << " " << zoom << "           \r";

    glutPostRedisplay();
    glutTimerFunc(16, BlitDisplay, 0);
}

void
ReshapeDisplay(int newHeight, int newWidth)
{
    if (newHeight == 0) newHeight = 1;

    float aspect = (float)newWidth / (float)newHeight;
    glViewport(0, 0, newWidth, newHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 1.0f, 120.0f);
    
    glutPostRedisplay();
}