#pragma once

#include "GLWindow.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkSurface.h"
#include "include/gpu/GrContext.h"

// This object connects the Skia library to the OpenGL window,
// and provides a method to draw.
// Override the paintThisFrame method to use it.
class ISkiaGLWindow {
public:
        ISkiaGLWindow(GLWindow *glWindow);
        ~ISkiaGLWindow() = default;

        virtual void paintThisFrame(SkCanvas *skiaContext) = 0;

private:
        // Reference OpenGL window
        GLWindow *m_glWindow;

        // Skia Canvas is the object we use to draw shapes
        SkCanvas* m_skiaContext = nullptr;
        sk_sp<GrContext> m_grContext = nullptr;
        sk_sp<SkSurface> obtainSkiaSurfaceFromCurrentGLContext();
        SkCanvas* obtainSkCanvas();
        // we store skia surface here to keep it in memory
        sk_sp<SkSurface> m_skiaSurface;

        // Call this function when something happens on the canvas and needs to be redrawn.
        // (An object changes, a new keyframe is selected, zoom in/out...)
        // We do this to save battery and not render frames every frame unnecessarily
        void requestPaint();
};
