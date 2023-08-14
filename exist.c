#include "holberton.h"
/**
 * check_file_existence - Verify if a file exists
 * @file_path: Path to the file
 * Return: 0 if the file exists or -1 if not
 */
int check_file_existence(char *file_path)
{
	int file_status;

	file_status = (open(file_path, O_RDONLY));
	if (file_status != -1)
	{
		close(file_status);
		return (0);
	}
	else
	{
		return (-1);
	}
}
