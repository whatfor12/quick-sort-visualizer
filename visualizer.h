#ifndef VISUALIZER
#define VISUALIZER

#define WIDTH 800
#define HEIGHT 600

void fill_coords(int arr[], int n);

void set_target(int i, int j, int *target_i, int *target_j, int coords[]);

void draw_rectangles(int *nums, int n, int *coords);

void move_rectangles(int speed, int i, int j, int coords[], int target_i,
                     int target_j);

#endif
