#include "sort.h"

/**
 * swap - function that swap two elements of an array
 * @x: an element to swap with y
 * @y: an element to swap with x
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - function that order a subset of an array.
 * @left: array first element.
 * @right: array last element.
 * @array: an array of ints.
 * @size: array size.
 * Return: The pivot position.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, i, j;

	pivot = array + right;
	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * recursive_sort - Implement the quicksort algorithm through recursion.
 * @array: an array of ints.
 * @size: size of array.
 * @left: first element in the array.
 * @right: last element in the array.
 *
 */

void recursive_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		recursive_sort(array, size, left, part - 1);
		recursive_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers.
 *
 * @array: array of integers.
 * @size: size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, size, 0, size - 1);
}
