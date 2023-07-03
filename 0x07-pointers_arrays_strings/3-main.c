#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * main - check the code
 *
 * Return: Always 0.
*/

int main(void)
{
	char *s = "hello, world";
	char *p = "helloIhello";
	char *f = "oleh";
	unsigned int n, z;

	n = strspn(s, f);
	z = strspn(p, f);
	printf("%u\n", n);
	printf("%u\n", z);
	return (0);
}
