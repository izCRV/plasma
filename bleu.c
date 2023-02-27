#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 30

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void draw_plasma() {
    int x, y;
    float cx = WIDTH / 2.0;
    float cy = HEIGHT / 2.0;
    float time = (float)clock() / CLOCKS_PER_SEC;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            float u = x / (float)WIDTH - 0.5;
            float v = y / (float)HEIGHT - 0.5;
            float a = atan2(v, u);
            float r = sqrt(u * u + v * v) + 0.5 * sin(2.0 * M_PI * (sqrt(u * u + v * v) + time));
            float b = sin(4.0 * M_PI * r + time) + sin(4.5 * M_PI * a + 3.0 * time);
            float c = sin(3.0 * M_PI * r + 2.0 * time) + sin(5.0 * M_PI * a + 4.0 * time);
            float d = sin(5.0 * M_PI * r + 4.0 * time) + sin(2.0 * M_PI * a + 5.0 * time);
            float intensity = 0.5 + 0.5 * (b + c + d) / 3.0;
            int color = (int)(intensity * 4.0);
            if (intensity > 0.5) {
                printf("\033[48;5;%dm ", 16 + color * 6);
            } else {
                printf("\033[40;1m \033[0m");
            }
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        clear_screen();
        draw_plasma();
        usleep(10000);
    }
    return 0;
}

