#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

void clear_screen();
void draw_plasma(int frame);
void draw_lightning();

int main()
{
    int frame = 0;

    srand(time(NULL));

    while (1)
    {
        clear_screen();
        draw_plasma(frame);
        draw_lightning();
        usleep(50000);
        frame++;
    }

    return 0;
}

void clear_screen()
{
    printf("\033[2J");
}

void draw_plasma(int frame)
{
    int x, y;
    char color_code;

    for (y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (x = 0; x < SCREEN_WIDTH; x++)
        {
            color_code = (char)(((int)(9.9 * sin(x / 3.0 + frame / 15.0) +
                9.9 * sin(y / 2.0 + frame / 10.0) + 9.9 * sin((x + y) / 4.0 + frame / 5.0))) + 97);

            printf("\033[38;5;%dm \033[48;5;%dm ", color_code, color_code);
        }
        printf("\033[0m\n");
    }
}

void draw_lightning()
{
    int x, y;
    char color_code;

    for (y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (x = 0; x < SCREEN_WIDTH; x++)
        {
            if (rand() % 1000 == 0)
            {
                color_code = (char)(232 + (rand() % 23));
                printf("\033[38;5;%dm%c\033[0m", color_code, (rand() % 2 == 0 ? '\\' : '/'));
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

