#include "main.h"

/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_number(n);
	return (res);
}
/**
 * print_long_int - prints a long integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_long_int(va_list l, flags_t *f)
{
	long int n = va_arg(l, long int);
	int res = count_digit_long(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_long_number(n);
	return (res);
}
/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}
int print_long_unsigned(va_list l, flag_t *f)
{
	long unsigned int u = va_arg(l, long unsigned int);
	char *str = convert (u, 10, 0);

	(void)f;
	return (_puts(str));
}
/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}
/**
 * print_long_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_long_number(long int n)
{
	long unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;
	if (n1 / 10)
		print_long_number(n1 / 10);
	_putchar((n1 % 10 ) + '0');
}
/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
int count_digit_long(long int i)
{
	unsigned int d = 0;
	long unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
