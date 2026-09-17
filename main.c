#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

#define SCALE 10
#define RECTANGLE_WIDTH 30
#define GAP 5

int main(void) {
    int nums[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(nums) / sizeof(int);

    InitWindow(WIDTH, HEIGHT, "Quick sort visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
