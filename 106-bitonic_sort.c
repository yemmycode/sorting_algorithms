#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
* swap_ints - Swaps two integers in an array.
* @a: first integer to swap.
* @b: second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* bitonic_merge - Sort a bitonic sequence inside an array of integers.
* @array: An array of integers.
* @size: The size of the array.
* @start: The starting index of the sequence in array to sort.
* @seq: The size of the sequence to sort.
* @flow: The direction to sort in.
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
size_t i, jump = seq / 2;

if (seq > 1)
{
for (i = start; i < start + jump; i++)
{
if ((flow == UP && array[i] > array[i + jump]) ||
(flow == DOWN && array[i] < array[i + jump]))
swap_ints(array + i, array + i + jump);
}
bitonic_merge(array, size, start, jump, flow);
bitonic_merge(array, size, start + jump, jump, flow);
}
}

/**
* bitonic_seq - Converts a block of an array of integers into a bitonic sequence.
* @array: Pointer to the array of integers.
* @size: The total size of the array.
* @start: The starting index of the block to convert.
* @seq: The size of the block to convert.
* @flow: The direction (UP or DOWN) to sort the bitonic sequence block.
*
* Description:
* This function recursively converts a block of the input array into a bitonic sequence.
* The input block is specified by the 'start' index and the 'seq' size.
* The 'flow' parameter determines whether the sequence should be increasing (UP) or decreasing (DOWN).
* The resulting bitonic sequence is merged back into the original array.
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
size_t cut = seq / 2;
char *str = (flow == UP) ? "UP" : "DOWN";

if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);

bitonic_seq(array, size, start, cut, UP);
bitonic_seq(array, size, start + cut, cut, DOWN);
bitonic_merge(array, size, start, seq, flow);

printf("Result [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);
}
}

/**
* bitonic_sort - Ascendingly sort an array of integers using the bitonic sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Prints the array after every swap. Works only for
* size = 2^k where k >= 0 (i.e., size equals powers of 2).
*/
void bitonic_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

bitonic_seq(array, size, 0, size, UP);
}
