/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:35 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/10 16:47:35 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int lmc(unsigned int a, unsigned int b)
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
		if (aux % a == 0 && aux % b = 0)
			return (aux);
		aux += max;
	}
}
