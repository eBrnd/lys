#include <avr/pgmspace.h>

#include "color.h"

// Logarithm table for smoother brightness changes.
const uint16_t pwmtable[] PROGMEM = {
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
	6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13,
	13, 14, 14, 15, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
	26, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 48,
	49, 51, 52, 53, 55, 56, 58, 60, 61, 63, 65, 66, 68, 70, 72, 74, 76, 78, 80, 82, 85, 87, 89, 92,
	94, 97, 100, 102, 105, 108, 111, 114, 117, 121, 124, 127, 131, 134, 138, 142, 146, 150, 154, 158,
	162, 167, 171, 176, 181, 186, 191, 196, 202, 207, 213, 219, 225, 231, 237, 244, 250, 257, 264,
	271, 279, 287, 294, 303, 311, 319, 328, 337, 346, 356, 366, 376, 386, 397, 407, 419, 430, 442,
	454, 467, 479, 493, 506, 520, 534, 549, 564, 579, 595, 612, 628, 646, 663, 682, 700, 719, 739,
	760, 780, 802, 824, 846, 870, 893, 918, 943, 969, 996, 1023
};

// HSV to RGB color space conversion.
// We use a HSV range from 0 .. 1535 so every (3*8bit) RGB value can be expressed as a HSV value.
void color_hsv2rgb(struct color_hsv* in, struct color_rgb* out) {

	uint16_t v = pgm_read_word(&pwmtable[in->v]);

	uint16_t col = ((uint32_t)v * in->s) / 255UL; // Span between darkest and brightest channel.
	uint16_t min = v - col; // Minimum (brightness of the darkest channel).
	uint8_t ramp = in->h >> 8; // Ramp of the HSV diagram we're on.
	uint16_t hue = in->h % 256; // Position on hue ramp.

	if (ramp % 2) // We're on a downward ramp.
		hue = 255 - hue;

	hue = ((uint32_t)hue * col) / 255UL; // Scale position on ramp to slope.
	hue += min;

	switch (ramp) {
	case 0:  // Green up.
		out->r = v;
		out->g = hue;
		out->b = min;
		break;
	case 1:  // Red down.
		out->r = hue;
		out->g = v;
		out->b = min;
		break;
	case 2:  // Blue up.
		out->r = min;
		out->g = v;
		out->b = hue;
		break;
	case 3:  // Green down.
		out->r = min;
		out->g = hue;
		out->b = v;
		break;
	case 4:  // Red up.
		out->r = hue;
		out->g = min;
		out->b = v;
		break;
	case 5:  // Blue down.
		out->r = v;
		out->g = min;
		out->b = hue;
		break;
	}
}
