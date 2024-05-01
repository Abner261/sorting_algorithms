#include "sort.h"
#include <stdio.h>

/**
 * swap - A function that swaps two integers in an array
 * @a: A pointer to the first integer to swap
 * @b: A pointer to the second integer to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - A function that partitions
 * the array using the Lomuto scheme
 * @array: The array of integers to partition
 * @low: Starting index of the partition
 * @high: ending index of the partition
 * @size: The size of the array
 * Return: partition index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * lomuto_quick_sort - A function that sorts an array of intengers in ascending
 * order using the Quick sort algorithm with Lomuto partition scheme
 * @array: An array of integers to sort
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: The size of the array
 */

void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		lomuto_quick_sort(array, low, pi - 1, size);
		lomuto_quick_sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 * @array: An array of integers to sort
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}
