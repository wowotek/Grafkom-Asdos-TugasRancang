#ifndef RENDER_HH
#define RENDER_HH

#include "common.hh"
#include "camera.hh"

void InitRenderer(Camera *, unsigned int *, void (*)());
void RenderDisplay();
void BlitDisplay(int);
void ReshapeDisplay(int, int);

#endif