#ifndef QUICK_SORT
#define QUICK_SORT

typedef struct {
    int left;
    int right;
    int pivot;
    int i;
    int j;
} State;

void swap(int *a, int *b);

void quick_sort(int *arr, int left, int right);

#endif
