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
#include "furniture.hh"

Camera camera;
ControlKey controlKey;
MousePos mousePos;
unsigned int * materialTexture;

void
InitTextures()
{
    materialTexture = new unsigned int[16];
    glGenTextures(16, materialTexture);
    LoadTexture(materialTexture[0] , "data/textures/grass1.bmp", 1024, 1024);
    LoadTexture(materialTexture[1] , "data/textures/hardwood.bmp", 1024, 1024);
    LoadTexture(materialTexture[2] , "data/textures/concrete.bmp", 1600, 1600);
    LoadTexture(materialTexture[3] , "data/textures/woodplank.bmp", 2048, 2048);
    LoadTexture(materialTexture[4] , "data/textures/maple.bmp", 944, 944);
    LoadTexture(materialTexture[5] , "data/textures/synthleather.bmp", 236, 177);
    LoadTexture(materialTexture[6] , "data/textures/fabric.bmp", 626, 625);
    LoadTexture(materialTexture[7] , "data/textures/NamePlateFront.bmp", 1024, 256);
    LoadTexture(materialTexture[8] , "data/textures/KasurKeras.bmp", 1899, 1144);
    LoadTexture(materialTexture[9] , "data/textures/Kasur.bmp", 768, 512);
    LoadTexture(materialTexture[10], "data/textures/bantal.bmp", 910, 603);

    LoadTexture(materialTexture[11], "data/skybox/back.bmp", 512, 512);
    LoadTexture(materialTexture[12], "data/skybox/front.bmp", 512, 512);
    LoadTexture(materialTexture[13], "data/skybox/left.bmp", 512, 512);
    LoadTexture(materialTexture[14], "data/skybox/right.bmp", 512, 512);
    LoadTexture(materialTexture[15], "data/skybox/top.bmp", 512, 512);

}

void
InitModules()
{
    InitControl(&camera, &controlKey, &mousePos);
    InitRenderer(&camera, materialTexture, &ControlCallback);
}

int
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutSetOption(GLUT_MULTISAMPLE, 8);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(2100, 100);
    glutCreateWindow("TR-GRAFKOM-ASDOS");
    InitTextures();
    glutFullScreen();

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

    InitModules();
    glutSetCursor(GLUT_CURSOR_NONE);

    glutTimerFunc(16, BlitDisplay, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glEnable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH); 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    

    glLoadIdentity();

    glutMainLoop();

    return 0;
}
