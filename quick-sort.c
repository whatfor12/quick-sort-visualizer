#include "main.h"
#include <stdio.h>

extern int firstRect;
extern int secondRect;

typedef struct {
    int left;
    int right;
    int pivot;
    int i;
    int j;
} State;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    int j = left;

    while (j < right) {
        if (arr[j] < pivot) {
            i++;
            get_indexes(&firstRect, &secondRect, i, j);
            swap(&arr[i], &arr[j]);
        }
    }

    get_indexes(&firstRect, &secondRect, right, i + 1);
    swap(&arr[right], &arr[i + 1]);

    return i + 1;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int partition_index = partition(arr, left, right);

        quick_sort(arr, left, partition_index - 1);
        quick_sort(arr, partition_index + 1, right);
    }
}
