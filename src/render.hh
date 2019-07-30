#ifndef RENDER_HH
#define RENDER_HH

#include "common.hh"
#include "texture.hh"
#include "camera.hh"

void InitRenderer(Camera *, void (*)());
void RenderDisplay();
void BlitDisplay(int);
void ReshapeDisplay(int, int);

#endif