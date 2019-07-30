#include <iostream>
#include <map>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "common.hh"
#include "control.hh"
#include "render.hh"
#include "texture.hh"

Camera camera;
ControlKey controlKey;
MousePos mousePos;

void
Init()
{
    InitControl(&camera, &controlKey, &mousePos);
    InitRenderer(&camera, &ControlCallback);
}

int
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1600, 900);
    glutInitWindowPosition(2100, 100);
    glutCreateWindow("TR-GRAFKOM-ASDOS");

    // Mouse
    glutMouseFunc(MouseButtonEventHandler);
    glutMotionFunc(MouseDragEventHandler);
    glutPassiveMotionFunc(MouseMoveEventHandler);
    
    // Keyboard
    glutKeyboardFunc(KeyboardDownEventHandler);
    glutKeyboardUpFunc(KeyboardUpEventHandler);
    glutSpecialFunc(KeyboardSpecialDownEventHandler);
    glutSpecialUpFunc(KeyboardSpecialUpEventHandler);

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(ReshapeDisplay);

    glViewport(0, 0, 1600, 900);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0f, (float)(900) / (float)(1600), 1.0f, 1000.0f
    );

    Init();
    glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);

    glutTimerFunc(16, BlitDisplay, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    glEnable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH); 

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    

    glLoadIdentity();

    glutMainLoop();

    return 0;
}
