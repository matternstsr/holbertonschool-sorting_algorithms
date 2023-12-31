#include "sort.h"

/**
 * bubble_sort - Calls function
 * @array: Array to be sorted
 * @size: Size of array
 * Description: Function that sorts an array using the bubble sort method
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int c, n, t;

	if (!array)
		return;

	for (c = 0; c < size - 1; c++)
	{
		for (n = 0; n < size - c - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				t = array[n];
				array[n] = array[n + 1];
				array[n + 1] = t;
				print_array(array, size);
			}
		}
	}
}
