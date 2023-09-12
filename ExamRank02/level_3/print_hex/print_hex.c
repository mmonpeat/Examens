/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:21:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 18:38:13 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printhex(int num);
int		ft_atoi(char *s);

int main(int ac, char **av)
{
	if (ac == 2)
		ft_printhex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}

void ft_printhex(int num)
{
	char *hex = "0123456789abcdef";

	if (num >= 16)
		ft_printhex(num / 16);
	write(1, &hex[num % 16], 1);
}

int ft_atoi(char *s)
{
	int res = 0;

	while (*s && (*s >= '0' && *s <= '9'))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}
