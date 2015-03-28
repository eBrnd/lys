#include "color.h"

// HSV to RGB color space conversion.
// We use a HSV range from 0 .. 1536 so every (3*8bit) RGB value can be expressed as a HSV value.
void color_hsv2rgb(struct color_hsv* in, struct color_rgb* out) {

  uint16_t v = 4 * in->v;

  uint16_t col = ((uint32_t)v * in->s) / 255UL; // Span between darkest and brightest channel.
  uint16_t min = v - col; // Minimum (brightness of the darkest channel).
  uint8_t ramp = in->h >> 8; // Ramp of the HSV diagram we're on.
  uint16_t hue = in->h % 256; // Position on hue ramp.

  if (ramp % 2) // We're on a downward ramp.
    hue = 255 - hue;

  hue = ((uint32_t)hue * col) / 255UL; // Scale position on ramp to slope.
  hue += min;

  min /= 4;
  hue /= 4;

  switch (ramp) {
  case 0:  // Green up.
    out->r = in->v;
    out->g = hue;
    out->b = min;
    break;
  case 1:  // Red down.
    out->r = hue;
    out->g = in->v;
    out->b = min;
    break;
  case 2:  // Blue up.
    out->r = min;
    out->g = in->v;
    out->b = hue;
    break;
  case 3:  // Green down.
    out->r = min;
    out->g = hue;
    out->b = in->v;
    break;
  case 4:  // Red up.
    out->r = hue;
    out->g = min;
    out->b = in->v;
    break;
  case 5:  // Blue down.
    out->r = in->v;
    out->g = min;
    out->b = hue;
    break;
  }
}
