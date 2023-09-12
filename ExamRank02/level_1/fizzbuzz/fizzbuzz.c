/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:32:53 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/17 19:53:51 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_write_number(int num);

int	main()
{
	int i;

	i = 0;
	while(i != 101)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if( i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else
			ft_write_number(i);
		i++;
		write(1, "\n", 1);
	}
}

void	ft_write_number(int num)
{
	char	str[10] = "0123456789";

	if (num > 9)
		ft_write_number(num / 10);
	write(1, &str[num % 10], 1);
}
