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
	int i = 0, re = 0;
	int count = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			re = 0;
			i++;
			while (format[i] == ' ')
			{
				re++;
				i++;
			}
			re += kind(format[i], args);
			count += re;
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
 * kind - it's the base boooyy
 * @c: pointer to the input
 * @args: args
 * Return: the size.
*/


int kind(char c, va_list args)
{

	int nona = 0, j = 0;
	long int i = 0;
	char *st, a, arr[] = "(null)", *in;

	if (c == '%')
		nona += _putchar('%');
	else if (c == 's')
	{
		st = va_arg(args, char *);
		if (!st)
		{
			while (arr[i])
				nona += _putchar(arr[i]);
			return (nona);
		}
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
	else if (c == 'i' || c == 'd')
	{
		i = va_arg(args, long int);
		if (i < 0)
		{
			_putchar('-');
			i *= -1;
		}
		in = tost(i);
		while (in[j])
			j++;
		nona += j;
		j--;
		for (; j >= 0; j--)
			_putchar(in[j]);
		free (in);
	}
	return (nona);
}
char *tost(long int num)
{
	char *st = malloc(sizeof(char)* 20);
	int i = 0;

	while (num != 0)
	{
		st[i] = (num % 10 ) + 48;
		i++;
		num /= 10;
	}
	return (st);
}
