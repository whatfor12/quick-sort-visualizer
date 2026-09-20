#include "quick-sort.h"
#include "visualizer.h"
#include <raylib.h>
#include <stdbool.h>

int main(void) {
    int nums[] = {5, 13, 6, 9, 12, 11, 8};
    int len = sizeof(nums) / sizeof(int);

    quick_sort(nums, 0, len - 1);

    int coords[len];

    int target_i;
    int target_j;

    fill_coords(coords, len);

    int speed = 1;
    bool moving = false;

    InitWindow(WIDTH, HEIGHT, "Quick sort visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_SPACE)) {
            set_target(1, 4, &target_i, &target_j, coords);

            moving = true;
        }

        move_rectangles(moving, speed, 1, 4, coords, target_i, target_j);

        draw_rectangles(nums, len, coords);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
