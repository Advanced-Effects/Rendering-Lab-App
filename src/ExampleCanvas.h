#pragma once

#include "ISkiaGLWindow.h"

class ExampleCanvas : public ISkiaGLWindow {
public:
        ExampleCanvas(GLWindow *glWindow);
        ~ExampleCanvas() = default;

        // What to do when a repaint is asked for
        void paintThisFrame(SkCanvas *skiaContext) override;

private:
        // Re-draw the screen ONLY when it is necessary
        void requestRepaint();
};
