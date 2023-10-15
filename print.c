#include "main.h"
#include <unistd.h>

/**
 * _printf - it's the base boooyy
 * @format: pointer to the input
 * Return: the size.
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += kind(format[i], args);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/**
 * _printf - it's the base boooyy
 * @format: pointer to the input
 * Return: the size.
*/


int kind(char c, va_list args)
{

	int nona = 0, i = 0;
	char *st, a;

	if (c == '%')
		nona += _putchar('%');
	else if (c == 's')
	{
		st = va_arg(args, char *);
		while (st[i])
		{
			nona += _putchar(st[i]);
			i++;
		}
		
	}
	else if (c == 'c')
	{
		a = va_arg(args, int);
		nona += _putchar(a);
	}
	return (nona);
}
