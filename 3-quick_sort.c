#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - A function that swaps two integers in an array
 * @a: A pointer to the first integer to swap
 * @b: A pointer to the second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - A function that partitions
 * the array using the Lomuto scheme
 * @array: The array of integers to partition
 * @size: The size of the array
 * @left: The starting index of the partition
 * @right: The ending index of the partition
 *
 * Return: The final partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - A function that sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the partition
 * @right: The ending index of the partition
 *
 * Description: Uses the Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 * @array: An array of integers to sort
 * @size: The size of the array
 *
 * Description: Uses the Lomuto partition scheme
 * prints the array after each swap of two elements
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
