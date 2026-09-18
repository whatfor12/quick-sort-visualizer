#include <raylib.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600

#define SCALE 25
#define RECTANGLE_WIDTH 30
#define GAP 10

typedef struct {
    int x;
    int y;
    int width;
    int height;
    Color color;
} Rect;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int nums[2] = {7, 3};
    int coords[2] = {200, 240};
    int speed = 1;
    bool moving = false;

    InitWindow(WIDTH, HEIGHT, "Quick sort visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_SPACE)) {
            moving = true;
        }

        for (int i = 0; i < 2; i++) {
            int height = nums[i] * SCALE;
            Rect newRect = {.x = coords[i],
                            .y = HEIGHT - height,
                            .width = RECTANGLE_WIDTH,
                            .height = height,
                            .color = WHITE};

            if (moving) {
                if (i == 0 && coords[i] != 240)
                    coords[i] += speed;

                if (i == 1 && coords[i] != 200)
                    coords[i] -= speed;
            }

            DrawRectangle(newRect.x, newRect.y, newRect.width, newRect.height,
                          newRect.color);
        }

        if (moving && coords[0] == 240 && coords[1] == 200) {
            swap(&nums[0], &nums[1]);
            swap(&coords[0], &coords[1]);
            moving = false;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
