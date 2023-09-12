/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:09:51 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 18:20:19 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnum(int n);

int main(int ac, char **av)
{
	(void)av;
	ft_putnum(ac - 1);
	write(1, "\n", 1);
	return (0);
}

void ft_putnum(int n)
{
	if (n > 9)
		ft_putnum(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}
