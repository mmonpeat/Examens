/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:29:57 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 14:56:06 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi_base(const char *s, int str_base);
char	to_lower(char c);
int		ft_get_digit(char c, int str_base);

/*
int main() 
{
    const char *s = "12FDB3"; // Example input string
    int base = 16; // Base 16 (hexadecimal)

    int result = ft_atoi_base(s, base);

    printf("The result is: %d\n", result);

    return 0;
}*/

int		ft_atoi_base(const char *s, int str_base)
{
	int sign = 1;
	int digit = 0;
	int res = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while ((digit = ft_get_digit(to_lower(*s), str_base)) >= 0)
	{
		res = res * str_base;
		res = res + (digit * sign);
		s++;
	}
	return (res);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int ft_get_digit(char c, int str_base)
{
	int max_digit;
	if (str_base <= 10)
		max_digit = str_base + '0';
	else
		max_digit = str_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
			return (-1);
}

