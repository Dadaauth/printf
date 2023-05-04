#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_by_char - prints a string character by character
 * @str: the string to print
 * Return: the amount of characters printed
 */
int print_by_char(char *str)
{
	int i = 0, len = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}
/**
 * _printf - the main printf function
 * @format: the format string for _printf
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_ptr;
	int i = 0, len = 0;
	char *str;

	va_start(arg_ptr, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 's':
					str = va_arg(arg_ptr, char*);
					if (str != NULL)
						len += print_by_char(str);
					break;
				case 'c':
					_putchar(va_arg(arg_ptr, int));
					len++;
					break;
				case '%':
					_putchar('%');
					len++;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (len);
}
