#include "main.h"
#include <stdio.h>
int main(void)
{
	int i;

	_printf("%");
	_printf("%");
	i = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char*)0);
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("rtn is %d", i);
	_printf("\nthis is an int%d, yet another int %i\n", 21, -234);
	_printf(NULL);
	return (0);
}
