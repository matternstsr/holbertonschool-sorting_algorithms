#include "sort.h"

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (size <= 1 || array == NULL)
        return;

    int stack[size];
    int top = -1;
    
    /* Push initial values of low and high to the stack*/
    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        /* Perform Lomuto partition */
        int pi = partition(array, low, high);

        /* If there are elements on the left side of pivot, push them to stack */
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        /* If there are elements on the right side of pivot, push them to stack */
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

/**
 * partition - Lomuto partition scheme.
 * @arr: Pointer to the array.
 * @lo: The lower index.
 * @hi: The higher index.
 * Return: Pivot index.
 */
int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo - 1;

    for (int j = lo; j <= hi - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            /* Swap arr[i] and arr[j] */
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    /* Swap arr[i+1] and arr[hi] to place pivot in correct position */
    int temp = arr[i + 1];
    arr[i + 1] = arr[hi];
    arr[hi] = temp;

    return i + 1;
}

