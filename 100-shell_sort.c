#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - A function that sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: An array of integers to sort
 * @size: The size of the array
 *
 * Description: Uses the Knuth interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
