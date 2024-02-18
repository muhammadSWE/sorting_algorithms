#include "sort.h"
#include <unistd.h>

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - recursively sorts an array using the quick
 * sort algorithm
 * @array: array to be sorted
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of the array
 * Return: void
*/
void quick_sort_rec(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot = partition(array, low, high, size);

		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * partition - partitions an array for quick sort algorithm
 * @array: array to be partitioned
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of the original array
 * Return: the new pivot after partitioning
*/
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (j != i)
			{
				swap_int(&array[j], &array[i]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap_int - swaps 2 elements of an array of ints
 * @a: first element
 * @b: second element
 * Return: void
*/
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
