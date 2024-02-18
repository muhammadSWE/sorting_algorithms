#include "sort.h"

/**
 * selection_sort - sorts an array using selection
 * sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t unsorted_i, min_i, i;

	if (!array || size < 2)
		return;

	for (unsorted_i = 0; unsorted_i <= size - 1; unsorted_i++)
	{
		min_i = unsorted_i;

		for (i = unsorted_i + 1; i <= size - 1; i++)
		{
			if (array[i] < array[min_i])
				min_i = i;
		}

		if (array[min_i] < array[unsorted_i])
		{
			swap_int(&array[unsorted_i], &array[min_i]);
			print_array(array, size);
		}
	}

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
