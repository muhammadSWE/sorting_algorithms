#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);

#endif
