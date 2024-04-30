#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Determines the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Returns: The maximum integer found in the array.
 */
int get_max(int *array, int size)
{
    int max_val, i;

    for (max_val = array[0], i = 1; i < size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }

    return max_val;
}

/**
 * radix_counting_sort - Sorts the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: The significant digit to sort by.
 * @buff: A buffer to hold the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        buff[count[(array[i] / sig) % 10] - 1] = array[i];
        count[(array[i] / sig) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the least significant digit (LSD) radix sort algorithm.
 * Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int max_val, sig, *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    max_val = get_max(array, size);
    for (sig = 1; max_val / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buff);
        print_array(array, size);
    }

    free(buff);
}
