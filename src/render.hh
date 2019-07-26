#ifndef RENDER_HH
#define RENDER_HH

#include "common.hh"

void InitRenderer(CameraData *, void (*)());
void RenderDisplay();
void BlitDisplay(int);
void ReshapeDisplay(int, int);

#endif