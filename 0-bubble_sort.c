#include "sort.h"

/**
 * bubble_sort - Sort an array of integers using the bubble sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		int swapped = 0;
		size_t j;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}
