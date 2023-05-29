#include <stdio.h>
#include <stdarg.h>

/**
 * Characters printed
 *
 *
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
			
			//Conversion specifier
			switch (*format)
			{
				case 'c':
					{
						// Retrieve the next argument and print it as a character
						int ch = va_arg(args, int);
						putchar(ch);
						count++;
						break;
					}
				case 's':
					{
						// Retrieve the next argument and print it as a string
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
						// Print a literal '%'
						putchar('%');
						count++;
						break;
					}
				default:
					// If an unsupported conversion 
					// ... specifier is encountered, ignore it
					break;
			}
		}
		else
		{
			// Print regular characters
			putchar(*format);
			count++;
		}
		format++; // Move to the next character in the format string
	}
	
	va_end(args);
	return count;
}
