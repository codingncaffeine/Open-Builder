// The pointer's button state where the game reads it outside its window messages (the city view's right-drag test). The
// Linux application defines it from its windowing layer; the Mac build asks CoreGraphics instead.
#pragma once

namespace platform {

bool RightMouseButtonDown();

}  // namespace platform
