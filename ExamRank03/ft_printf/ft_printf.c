/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:40:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/09/12 14:34:40 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void put_string(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void put_digit(long long int num, int base, int *len)
{
	char *hex = "0123456789abcdef";
	
	if (num < 0)
	{
		num *= -1;
		*len += write(1,"-", 1);
	}
	if (num >= base)
		put_digit((num/base), base, len);
	*len += write(1, &hex[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;

	va_list pointer;
	va_start(pointer, format);

	while(*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &len);
			else if(*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &len);
			else if(*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), len);
}

int main()
{
	int num = 1234;
	char *str = "hola";
	int hex = 16;
	ft_printf("D: %d \nS: %s\n X:%x\n", num, str, hex);
	printf("D: %d \nS: %s\n X:%x\n", num, str, hex);
	return (0);
}
