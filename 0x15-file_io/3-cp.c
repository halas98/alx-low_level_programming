#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int c(const char *a, const char *b);

int main(int ac, char **av)
{
if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
exit(97);
}

if (c(av[1], av[2]) != 0)
{
exit(99);
}

return (0);
}

int c(const char *a, const char *b)
{
int x, y, z, w, r;
char d[BUFFER_SIZE];

x = open(a, O_RDONLY);
if (x == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", a);
return (-1);
}

y = open(b, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (y == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", b);
close(x);
return (-1);
}

while ((z = read(x, d, BUFFER_SIZE)) > 0)
{
w = write(y, d, z);
if (w != z)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", b);
close(x);
close(y);
return (-1);
}
}

if (z == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", a);
close(x);
close(y);
return (-1);
}

if (close(x) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", x);
return (-1);
}

if (close(y) == -1)
{


