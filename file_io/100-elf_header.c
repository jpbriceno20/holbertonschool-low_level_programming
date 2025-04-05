#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * swap16 - Swaps bytes of a 16-bit number.
 * @val: The 16-bit value to swap.
 *
 * Return: The swapped value.
 */
unsigned short swap16(unsigned short val)
{
	return (((val >> 8) & 0xff) | ((val & 0xff) << 8));
}

/**
 * swap32 - Swaps bytes of a 32-bit number.
 * @val: The 32-bit value to swap.
 *
 * Return: The swapped value.
 */
unsigned int swap32(unsigned int val)
{
	return (((val >> 24) & 0xff) |
		(((val >> 16) & 0xff) << 8) |
		(((val >> 8) & 0xff) << 16) |
		((val & 0xff) << 24));
}

/**
 * main - Displays the information contained in the ELF header
 *        at the start of an ELF file.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success; exits with code 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd, i;
	ssize_t rd;
	unsigned char header[64];
	unsigned short e_type;
	unsigned int e_entry;

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
	rd = read(fd, header, sizeof(header));
	/* Minimum ELF header size for ELF32 is 52 bytes */
	if (rd < 52)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	/* Verify ELF magic */
	if (header[EI_MAG0] != 0x7f || header[EI_MAG1] != 'E' ||
	    header[EI_MAG2] != 'L' || header[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
	printf("  Class:                             ");
	if (header[EI_CLASS] == ELFCLASS32)
		printf("ELF32");
	else if (header[EI_CLASS] == ELFCLASS64)
		printf("ELF64");
	else
		printf("<unknown: %x>", header[EI_CLASS]);
	printf("\n");
	printf("  Data:                              ");
	if (header[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian");
	else if (header[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian");
	else
		printf("<unknown: %x>", header[EI_DATA]);
	printf("\n");
	printf("  Version:                           %d", header[EI_VERSION]);
	if (header[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
	printf("  OS/ABI:                            ");
	switch (header[EI_OSABI])
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
			printf("<unknown: %x>", header[EI_OSABI]);
			break;
	}
	printf("\n");
	printf("  ABI Version:                       %d\n",
	       header[EI_ABIVERSION]);

	/* For ELF32 and ELF64, type is at offset 16 and entry point at offset 24.
	 * We extract them as follows. If the data encoding is big endian,
	 * we swap the multi-byte fields.
	 */
	if (header[EI_CLASS] == ELFCLASS32)
	{
		unsigned short *p_type = (unsigned short *)(header + 16);
		unsigned int *p_entry = (unsigned int *)(header + 24);
		if (header[EI_DATA] == ELFDATA2MSB)
		{
			e_type = swap16(*p_type);
			e_entry = swap32(*p_entry);
		}
		else
		{
			e_type = *p_type;
			e_entry = *p_entry;
		}
	}
	else if (header[EI_CLASS] == ELFCLASS64)
	{
		unsigned short *p_type = (unsigned short *)(header + 16);
		unsigned long *p_entry = (unsigned long *)(header + 24);
		if (header[EI_DATA] == ELFDATA2MSB)
		{
			e_type = swap16(*p_type);
			/* For ELF64, we assume the entry point fits in 32 bits for display */
			e_entry = swap32((unsigned int)*p_entry);
		}
		else
		{
			e_type = *p_type;
			e_entry = (unsigned int)*p_entry;
		}
	}
	else
	{
		e_type = 0;
		e_entry = 0;
	}
	printf("  Type:                              ");
	switch (e_type)
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
			printf("<unknown: %x>", e_type);
			break;
	}
	printf("\n");
	printf("  Entry point address:               ");
	if (header[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", e_entry);
	else
		printf("0x%lx\n", (unsigned long)e_entry);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}
