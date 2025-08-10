#include "ExampleCanvas.h"

#include <iostream>
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"

#include "GLWindow.h"

ExampleCanvas::ExampleCanvas(GLWindow *glWindow)
        : ISkiaGLWindow(glWindow) {};

void ExampleCanvas::paintThisFrame(SkCanvas *skiaContext) {
    std::cout << "Painting!" << std::endl;

    skiaContext->restore();

    SkPaint paint;
    paint.setColor(SkColors::kRed);

    auto rect = SkRect::MakeWH(200, 300);

    skiaContext->drawRect(rect, paint);

    skiaContext->save();
};
