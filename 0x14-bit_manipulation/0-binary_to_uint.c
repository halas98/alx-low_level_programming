#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: A pointer to the binary string.
 *
 * Return: The converted unsigned int, or 0 if invalid input.
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		/* Left shift the result and add the current bit (0 or 1) */
		result = (result << 1) | (*b - '0');
		b++;
	}

	return (result);
}

