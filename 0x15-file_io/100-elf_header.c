#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFSIZE 128

int validate_elf_header(Elf64_Ehdr *header);
void display_elf_header(Elf64_Ehdr *header);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read != sizeof(header) || !validate_elf_header(&header))
	{
		fprintf(stderr, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_header(&header);

	close(fd);
	return (0);
}

int validate_elf_header(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
		header->e_ident[EI_MAG1] != ELFMAG1 ||
		header->e_ident[EI_MAG2] != ELFMAG2 ||
		header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		return (0);
	}
	return (1);
}

void display_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
}

