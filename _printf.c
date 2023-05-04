#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_int - prints integers
 * @num: the int
 * Return: the number of characters printed
 */
int print_int(int num)
{
	char str[20];
	int i = 0;
	int len = 0;

	if (num < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		num = -num;
	}
	do
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	while (num > 0);
	while (i > 0)
	{
		write(STDOUT_FILENO, &str[--i], 1);
		len++;
	}
	return (len);
}
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
int p_switch(va_list arg, char format);
/**
 * _printf - the main printf function
 * @format: the format string for _printf
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_ptr, agp2;
	int i = 0, len = 0;
	char t, s;

	if (format == NULL)
		return (-1);
	va_start(arg_ptr, format);
	va_copy(agp2, arg_ptr);
	while (format[i])
	{
		s = format[i];
		t = format[i + 1];
		if (s == '%' && !t)
			return (-1);
		if (s == '%' && (t == 'c' || t == 's' || t == '%' || t == 'd' || t == 'i'))
		{
			i++;
			len += p_switch(agp2, format[i]);
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
/**
 * p_switch - switch statement to check for format specifiers
 * @arg: va_list variable type
 * @format: format character
 * Return: number of characters printed
 */
int p_switch(va_list arg, char format)
{
	int len = 0;
	char *str;

	switch (format)
	{
		case 's':
			str = va_arg(arg, char*);
			if (str != NULL)
				len = print_by_char(str);
			else
				len = print_by_char("(null)");
			break;
		case 'c':
			_putchar(va_arg(arg, int));
			len = 1;
			break;
		case 'd':
			print_int(va_arg(arg, int));
			len = 1;
			break;
		case 'i':
			print_int(va_arg(arg, int));
			len = 1;
			break;
		case '%':
			_putchar('%');
			len = 1;
			break;
	}
	va_end(arg);
	return (len);
}
