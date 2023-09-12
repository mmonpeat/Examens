/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:13:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/11 11:43:32 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_tab_mult(char *s);
static void	ft_putnum(int num);
static int	ft_atoi(char *s);

int main(int ac, char **av)
{
	if (ac == 2)
		ft_tab_mult(av[1]);
	else
		write(1,"\n", 1);
	return (0);
}

static void ft_tab_mult(char *s)
{
	int num;
	int i;

	num = ft_atoi(s);
	i = 0;
	while (i < 10)
	{
		ft_putnum(i);
		write(1, " x ", 3);
		ft_putnum(num);
		write(1, " = ", 3);
		ft_putnum(i * num);
		write(1, "\n", 1);
		i++;
	}
}

static int ft_atoi(char *s)
{
	int res;

	res = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}

static void ft_putnum(int num)
{
	char n;

	if (num >= 10)
		ft_putnum(num / 10);
	n = (num % 10) + '0';
	write(1, &n, 1);
}
