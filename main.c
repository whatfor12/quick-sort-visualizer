#include "quick-sort.h"
#include "visualizer.h"
#include <raylib.h>

void get_indexes(int *i, int *j, int l, int m) {
    *i = l;
    *j = m;
}

int firstRect;
int secondRect;
int firstRectTarget;
int secondRectTarget;

int main(void) {
    int nums[] = {5, 13, 6, 9, 12, 11, 8};
    int len = sizeof(nums) / sizeof(int);

    int coords[len];
    fill_coords(coords, len);

    int speed = 1;

    State state;

    InitWindow(WIDTH, HEIGHT, "Quick sort visualizer");
    SetTargetFPS(60);

    quick_sort(nums, 0, len - 1);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        set_target(firstRect, secondRect, &firstRectTarget, &secondRectTarget,
                   coords);

        move_rectangles(speed, firstRect, secondRect, coords, firstRectTarget,
                        secondRectTarget);

        draw_rectangles(nums, len, coords);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
