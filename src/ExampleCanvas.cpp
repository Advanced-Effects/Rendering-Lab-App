#include "ExampleCanvas.h"

#include "GLWindow.h"

ExampleCanvas::ExampleCanvas(GLWindow *glWindow)
        : ISkiaGLWindow(glWindow) {};

void ExampleCanvas::paintThisFrame(SkCanvas *skiaContext) {};

void ExampleCanvas::requestRepaint() {};

