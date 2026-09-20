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

void fill_coords(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 200 + i * (RECTANGLE_WIDTH + GAP);
    }
}

void move_rectangles(bool is_moving, int speed, int i, int j, int coords[],
                     int target_i, int target_j) {
    if (!is_moving) {
        return;
    }

    if (coords[i] < target_i) {
        coords[i] += speed;
    }

    if (coords[i] > target_i) {
        coords[i] -= speed;
    }

    if (coords[j] < target_j) {
        coords[j] += speed;
    }

    if (coords[j] > target_j) {
        coords[j] -= speed;
    }
}

void set_target(int i, int j, int *target_i, int *target_j, int coords[]) {
    *target_i = coords[j];
    *target_j = coords[i];
}

int main(void) {
    int nums[] = {5, 13, 6, 9, 12, 11, 8};
    int len = sizeof(nums) / sizeof(int);

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

        for (int i = 0; i < len; i++) {
            int height = nums[i] * SCALE;
            Rect newRect = {.x = coords[i],
                            .y = HEIGHT - height,
                            .width = RECTANGLE_WIDTH,
                            .height = height,
                            .color = WHITE};

            DrawRectangle(newRect.x, newRect.y, newRect.width, newRect.height,
                          newRect.color);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
