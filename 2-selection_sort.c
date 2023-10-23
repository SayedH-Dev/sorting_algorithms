#include "sort.h"

/**
* selection_sort - function sorts array of integers in ascending order
*
* @array: array of integer
* @size: number of elements
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t minValue;
	int temp;

	for (i = 0; i < size; i++)
	{
		minValue = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minValue])
				minValue = j;
		}
		if (minValue != i)
		{
			temp = array[i];
			array[i] = array[minValue];
			array[minValue] = temp;

			print_array(array, size);
		}
	}
}
