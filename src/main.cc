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
InitEngine()
{
    InitControl(&camera, &controlKey, &mousePos);
    InitRenderer(&camera, &ControlCallback);
}

void
InitControl()
{
    // Mouse
    glutMouseFunc(MouseButtonEventHandler);
    glutMotionFunc(MouseDragEventHandler);
    glutPassiveMotionFunc(MouseMoveEventHandler);
    
    glutSetCursor(GLUT_CURSOR_NONE);

    // Keyboard
    glutKeyboardFunc(KeyboardDownEventHandler);
    glutKeyboardUpFunc(KeyboardUpEventHandler);
    glutSpecialFunc(KeyboardSpecialDownEventHandler);
    glutSpecialUpFunc(KeyboardSpecialUpEventHandler);
}

int
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(2100, 100);
    glutCreateWindow("TR-GRAFKOM-ASDOS");
    glutFullScreen();

    glutSetOption(GLUT_MULTISAMPLE, 8);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glEnable(GLUT_MULTISAMPLE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH); 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);

    InitControl();

    glutDisplayFunc(RenderDisplay);
    glutReshapeFunc(ReshapeDisplay);

    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0f, glutGet(GLUT_WINDOW_HEIGHT) / glutGet(GLUT_WINDOW_WIDTH), 1.0f, 1000.0f
    );


    InitEngine();
    glutTimerFunc(16, BlitDisplay, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);

    glLoadIdentity();

    glutMainLoop();

    return 0;
}
