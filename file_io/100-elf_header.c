#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or exits with status code 98 on error.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd, i;
	ssize_t rd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(fd, &header, sizeof(header));
	if (rd != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	/* Verify that the file is an ELF file */
	if (header.e_ident[EI_MAG0] != 0x7f ||
	    header.e_ident[EI_MAG1] != 'E' ||
	    header.e_ident[EI_MAG2] != 'L' ||
	    header.e_ident[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header.e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
	printf("  Class:                             ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32");
	else if (header.e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64");
	else
		printf("<unknown: %x>", header.e_ident[EI_CLASS]);
	printf("\n");
	printf("  Data:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian");
	else if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian");
	else
		printf("<unknown: %x>", header.e_ident[EI_DATA]);
	printf("\n");
	printf("  Version:                           %d", header.e_ident[EI_VERSION]);
	if (header.e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		default:
			printf("<unknown: %x>", header.e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
	printf("  ABI Version:                       %d\n",
	       header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown: %x>", header.e_type);
			break;
	}
	printf("\n");
	printf("  Entry point address:               ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", (unsigned int)header.e_entry);
	else
		printf("0x%lx\n", header.e_entry);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}
