#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - A function that swaps two integers in an array
 *
 * @a: The first integer to swap
 *
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
 * max_heapify - A function that rearranges the elements
 * in the array to form a max heap
 *
 * @array: An array of integers representing a binary tree to heapify
 *
 * @size: The size of the array/tree
 *
 * @base: The index of the base row of the tree
 *
 * @root: The index of the root of the subtree to heapify
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - A function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 *
 * @array: An array of integers to sort
 *
 * @size: The size of the array
i *
 * Description: Implements the sift-down heap sort
 * algorithm prnts the array after each swap
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
