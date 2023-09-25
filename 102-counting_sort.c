#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: The number of elements in the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	for (i = 1; i < size; i++)
	{
	    if (array[i] > max)
			max = array[i];
	}	
	return max;
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	size_t max;
	int *count, *sorted;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	print_array(count, max + 1);

	free(count);
	free(sorted);
}
