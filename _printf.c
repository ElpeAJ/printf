#include <stdio.h>
#include <stdarg.h>
/**
*Characters printed
*Conversion specifier
*Retrieve the next argument and print it as a character
*Retrieve the next argument and print it as a string
*Print a literal '%'
*If an unsupported conversion
*... specifier is encountered, ignore it
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
switch (*format)
{
case 'c':
{
int ch = va_arg(args, int);

putchar(ch);

count++;

break;

}
case 's':
{
const char *str = va_arg(args, const char *);

while (*str != '\0')

{
putchar(*str);
str++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
break;
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
