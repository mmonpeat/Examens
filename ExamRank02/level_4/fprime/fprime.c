/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:44:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/24 19:42:26 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_fprime(int n);
int 	ft_isprime(int n);

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0] != '-')//per que no passin els negatius
		ft_fprime(atoi(av[1]));
	printf("\n");
	return (0);
}

void	ft_fprime(int n)
{
	int i = 2;
	int flag = 1;

	if (n == 1)
		printf("1");
	while (i <= n)
	{
		while ((n % i) == 0 && ft_isprime(i) == 1)
		{
			if (flag == 1)
				printf("%d", i);
			else
				printf("*%d", i);
			flag = 0;
			n /= i;
		}
		i++;
	}
}

int ft_isprime(int n)
{
	int i = 2;

	while (i < n)
	{
		if ((n % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
