#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Read and print a text file to standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 * Return: Number of letters read and printed, or 0 on error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	ssize_t read_bytes, written_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	read_bytes = fread(buffer, 1, letters, file);
	if (read_bytes == -1)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	written_bytes = write(STDOUT_FILENO, buffer, read_bytes);
	if (written_bytes != read_bytes)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);
	return (written_bytes);
}
