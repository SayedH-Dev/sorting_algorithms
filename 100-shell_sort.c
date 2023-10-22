#include "sort.h"

/**
 * shell_sort - function that uses Shell sorting algorithm
 * to sort integers in ascending order using Knuth sequence
 * @array: array to be sorted
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 1;
	int tmp;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
