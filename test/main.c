#include <pros.h>

void main() {
    print_string("Hello, world!");

    uint16_t x, y;
    uint16_t start_x = 100;
    uint16_t start_y = 100;
    uint16_t width = 200;
    uint16_t height = 150;
    uint8_t color = 4;

    for (y = start_y; y < start_y + height; y++) {
        for (x = start_x; x < start_x + width; x++) {
            draw_pixel(x, y, color);
        }
    }

    while(1);
}
