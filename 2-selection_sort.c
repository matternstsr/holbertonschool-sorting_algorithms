#include "sort.h"

/**
 * selection_sort - Calls function
 * @array: Array to be sorted
 * @size: Size of array given
 * Descrtiption: Function that sorts an array using the Selection
 * sort algotrithm
 * Return: 0
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;

		if (i != min_idx)
		{
			t = array[n];
			array[n] = array[n + 1];
			array[n + 1] = t;
			print_array(array, size);
		}
	}
}
