#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = 0;

	if (size <= 1 || array == NULL || size == 0)
		return;

	low = 0;
	high = size - 1;

	recursive_quick_sort(array, low, high, size);
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @arr: The array to be partitioned.
 * @lo: The lower index of the partition.
 * @hi: The higher index of the partition.
 * @size: The size of the array.
 * Return: The partition index.
 */
int lomuto_partition(int *arr, int lo, int hi, size_t size)
{
	int pivot = 0;
	int i = 0, j = 0;
	size_t tmp;

	pivot = arr[hi];
	i = lo - 1;

	for (j = lo; j <= hi; j++)
	{
		if (arr[j] <= pivot)
		{
			i += 1;
			if (i != j)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
		}
	}
	return (i);
}

/**
 * recursive_quick_sort - Recursive function to perform quicksort.
 * @arr: The array to be sorted.
 * @low: The lower index of the subarray.
 * @high: The higher index of the subarray.
 * @size: The size of the array.
 * Return: Nothing.
 */
void recursive_quick_sort(int *arr, int low, int high, size_t size)
{
	int pivot_index = 0;

	if (low < high)
	{
		pivot_index = lomuto_partition(arr, low, high, size);

		recursive_quick_sort(arr, low, pivot_index - 1, size);
		recursive_quick_sort(arr, pivot_index + 1, high, size);
	}
}

