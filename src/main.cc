#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "common.hh"
#include "control.hh"
#include "render.hh"

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(2450, 100);
    glutCreateWindow("TR-GRAFKOM-ASDOS");

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(ReshapeDisplay);

    glutMouseFunc(MouseButtonEventHandler);
    glutMotionFunc(MouseDragEventHandler);
    glutPassiveMotionFunc(MouseMoveEventHandler);

    glutTimerFunc(16, BlitDisplay, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    
    glShadeModel(GL_SMOOTH); 

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

    glLoadIdentity();

    glutMainLoop();

    return 0;
}