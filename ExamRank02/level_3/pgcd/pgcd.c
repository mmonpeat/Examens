/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:17:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/10 17:12:45 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//no cal que la funcio sigui unsigned
unsigned int ft_pgcd(int a, int b);

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%i",ft_pgcd(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
	return (0);
}

unsigned int ft_pgcd(int a, int b)
{
	unsigned int max;
	unsigned int aux;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		max = a;
	else
		max = b;
	aux = max;
	while (1)
	{
		if (aux % a == 0 && aux % b == 0)
			return (a * b / aux);
		aux += max;
	}
}
