#include "ISkiaGLWindow.h"

#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/GrContext.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkGraphics.h"

// The Skia Surface is the object we use to talk to the GPU
// In order to render to an OpenGL context, we need to obtain the
// SkSurface from the GL context directly.
// Ref: https://skia.org/docs/user/api/skcanvas_creation/
sk_sp<SkSurface> obtainSkiaSurfaceFromCurrentGLContext(GLWindow *glWindow) {
        auto glContext = glWindow->glContext();

        // Grabs the OpenGL context that is currently set as "current"
        // (we set it with `glfwMakeContextCurrent` in `main.cpp`)
        sk_sp<const GrGLInterface> interface = GrGLCreateNativeInterface();

        const GrContextOptions &grOptions = GrContextOptions();
        auto grContext = GrContext::MakeGL(interface, grOptions);

        int width = glWindow->width();
        int height = glWindow->height();
        SkImageInfo imageInformation = SkImageInfo::MakeN32Premul(width, height);


        SkSurfaceProps props(0, kUnknown_SkPixelGeometry);

        // Create the Skia Surface from the GL context
        return SkSurface::MakeRenderTarget(
                grContext.get(),
                SkBudgeted::kNo,
                imageInformation,
                kTopLeft_GrSurfaceOrigin,
                &props);
};

// The mission of this function is to connect the Skia Canvas with the OpenGL context (window)
// SkCanvas is the object we (users of the library) use to draw things on screen
SkCanvas* ISkiaGLWindow::obtainSkCanvas() {
        // NOTE: We put SkiaSurface in a class field to keep it in memory
        // So we can keep drawing (either it crashes)
        m_skiaSurface = obtainSkiaSurfaceFromCurrentGLContext(m_glWindow);
        if (!m_skiaSurface) {
                return nullptr;
        }

        // Initialize Skia so we can draw
        SkGraphics::Init();

        // SkSurfaceProps -> SkCanvas
        // The skia surface creates a SkCanvas, which we use to draw
        return m_skiaSurface->getCanvas();
};

void ISkiaGLWindow::requestPaint() {
    if (!m_skiaContext || !m_skiaSurface) return;

    paintThisFrame(m_skiaContext);
};

ISkiaGLWindow::ISkiaGLWindow(GLWindow *glWindow)
        : m_glWindow(glWindow) {
                //setDimensions(width, height);
                m_skiaContext = obtainSkCanvas();

                // When GL says it's okay to draw, request a redraw
                m_glWindow->setOnDrawRequest([this]() {
                    requestPaint();
                });
        };
