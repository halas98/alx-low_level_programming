#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
*/

int main(void)
{
	char *s = "hello";
	char *f;

	f = strchr(s, 'l');

	if (f != NULL)
	{
		printf("%s\n", f);
	}
	return (0);
}
