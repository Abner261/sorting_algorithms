#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		unsigned int x = i;
		int temp = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < temp)
				temp = array[j], x = j;
		}
		if (x != i)
		{
			array[x] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
