#include <stdio.h>
#include <stdarg.h>
/**
*_printf: This is the main function
*Conversion specifier
*Retrieve the next argument and print it as a character
*Retrieve the next argument and print it as a string
*Print a literal '%'
*If an unsupported conversion
*/
int _printf(const char *format, ...)
{
va_list args;

va_start(args, format);

int count = 0;

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
	int ch = va_arg(args, int);
	putchar(ch);
	count++;
}
else if
{
	(*format == 's')
		const char *str = va_arg(args, const char *);
	while (*str != '\0')
	{
		putchar(*str);
		str++;
		count++;
	}
}
else if
{
	(*format == '%')
		putchar('%');
	count++;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
