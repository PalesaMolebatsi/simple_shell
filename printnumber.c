#include "holberton.h"
/**
 * print_integer - Prints an integer, used to print the error message.
 * @num: Number to print.
 * Return: Number of characters printed.
 */
int print_integer(int num)
{
	unsigned int number;
	int chars_printed = 0;

	if (num < 0)
	{
		number = -num;
		chars_printed += _putchar('-');
	}
	else
	{
		number = num;
	}

	if (number / 10 != 0)
		chars_printed += print_integer(number / 10);

	chars_printed += _putchar(number % 10 + '0');
	return (chars_printed);
}
