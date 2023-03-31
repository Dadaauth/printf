#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent},
		};
	ph func_arrl[] = {
		{'d', print_long_int},
		{'i', print_long_int},
		{'u', print_long_unsigned},
		{'o', print_long_octal},
		{'x', print_long_hex},
		{'X', print_long_hex_big},
	};
	ph func_arrh[] = {
		{'d', print_short_int},
		{'i', print_short_int},
		{'u', print_short_unsigned},
		{'o', print_short_octal},
		{'x', print_short_hex},
		{'X', print_short_hex_big},
	};

	int flags = 14;
	int flags2 = 6;

	register int i; 
	register int j;

	if ('l' == s)
	{
		for (j = 0; j < flags2; j++)
		{
			if (func_arrl[i].c == *(s + 1))
			{
				return (func_arrl[i].f);
			}
		}

	}
	else if ('h' == s)
	{
		for (j = 0; j < flag2; j++)
		{
			if (func_arrh[i].c == *(s + 1))
			{
				return (func_arrh[i].f);
			}
		}
	}
	
	for (i = 0; i < flags; i++)
	{
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	}
	return (NULL);
}
