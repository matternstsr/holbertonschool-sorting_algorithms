#include "sort.h"

/**
 * quick_sort - Sort an array of integers in sort way
 * @array: pointer
 * @size: size
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int high = stack[top--];
	int low = stack[top--];
	int pi;
	int stack[size];
        int top = -1;

	if (size <= 1 || array == NULL || size == 0)
		return;

	/* Initialize a stack for iterative quicksort */
	stack[size];
	top = -1;

	/* Push initial values of low and high to the stack */
	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0) {
		/* Pop high and low from stack */
		high = stack[top--];
		low = stack[top--];

		/* Perform lomuto partition */
		pi = partition(array, low, high, size);

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
 * partition - lomuto partition scheme.
 * @arr: pointer.
 * @lo: the lower
 * @hi: the higher
 * Return: pivot index
 */

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo - 1;
    int j = lo;

    for (j = lo; j <= hi - 1; j++)
    {
        if (arr[j] <= pivot)
	{
            i++;
            quick_sort(&arr[i], &arr[j]);
        }
    }
    quick_sort(&arr[i + 1], &arr[hi]);
    return i + 1;
}
