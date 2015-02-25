#include "color.h"

// HSV to RGB color space conversion.
// We use a HSV range from 0 .. 1536 so every (3*8bit) RGB value can be expressed as a HSV value.
void color_hsv2rgb(struct color_hsv* in, struct color_rgb* out) {
  uint8_t col = (in->v * in->s) / 255;
  uint8_t min = in->v - col;

  // Find out which ramp of the HSV diagram we're on.
  if (in->h < 256) {         // Green up.
    uint8_t hue = in->h;
    hue = hue * col / 255;

    out->r = in->v;
    out->g = min + hue;
    out->b = min;
  } else if (in->h < 512) {  // Red down.
    uint8_t hue = in->h - 256;
    hue = (255 - hue) * col / 255;

    out->r = min + hue;
    out->g = in->v;
    out->b = min;
  } else if (in->h < 768) {  // Blue up.
    uint8_t hue = in->h - 512;
    hue = hue * col / 255;

    out->r = min;
    out->g = in->v;
    out->b = min + hue;
  } else if (in->h < 1024) { // Green down.
    uint8_t hue = in->h - 768;
    hue = (255 - hue) * col / 255;

    out->r = min;
    out->g = min + hue;
    out->b = in->v;
  } else if (in->h < 1280) { // Red up.
    uint8_t hue = in->h - 1024;
    hue = hue * col / 255;

    out->r = min + hue;
    out->g = min;
    out->b = in->v;
  } else if (in->h < 1536) { // Blue down.
    uint8_t hue = in->h -1280;
    hue = (255 - hue) * col / 255;

    out->b = min + hue;
    out->g = min;
    out->r = in->v;
  } else {
    // Fail.
  }
}
