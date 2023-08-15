#include "sort.h"

/**
 * partition - Lomuto partition scheme.
 * @arr: Pointer to the array.
 * @lo: The lower index.
 * @hi: The higher index.
 * Return: Pivot index.
 */
int partition(int arr[], int lo, int hi)
{
	int pivot, i, j, temp;

	pivot = arr[hi];
	i = lo - 1;

	for (j = lo; j <= hi - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i + 1];
	arr[i + 1] = arr[hi];
	arr[hi] = temp;

	return i + 1;
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	int stack[100];
	int top = -1;
	int high, low, pi;

	if (size <= 1 || array == NULL)
		return;

	/* Push initial values of low and high to the stack */
	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0) {
		high = stack[top--];
		low = stack[top--];

		/* Perform Lomuto partition */
		pi = partition(array, low, high);

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

