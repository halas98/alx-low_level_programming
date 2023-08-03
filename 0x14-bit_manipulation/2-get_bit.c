#include "main.h"

/**
* get_bit - Get the value of a bit at a given index.
* @n: The input number.
* @index: The index of the bit to retrieve, starting from 0.
*
* Return: The value of the bit at index or -1 if an error occurred.
*/
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask;
if (index >= sizeof(unsigned long int) * 8)
return (-1);

mask = 1UL << index;
return ((n & mask) != 0);
}

