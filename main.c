#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

#define SCALE 25
#define RECTANGLE_WIDTH 30
#define GAP 5

int main(void) {
    int nums[] = {7, 3};

    InitWindow(WIDTH, HEIGHT, "Quick sort visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_SPACE)) {
            int temp = nums[1];
            nums[1] = nums[0];
            nums[0] = temp;
        }

        for (int i = 0; i < 2; i++) {
            int height = nums[i] * SCALE;
            DrawRectangle(200 + i * (RECTANGLE_WIDTH + GAP), HEIGHT - height,
                          RECTANGLE_WIDTH, height, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
