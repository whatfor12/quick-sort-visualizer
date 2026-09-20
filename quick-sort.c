#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

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

int main(void) {
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(arr) / sizeof(int);

    quick_sort(arr, 0, n - 1);

    return 0;
}
