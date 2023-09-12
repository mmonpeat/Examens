/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:10:19 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:38:05 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	// n es el resultat de la potencia
	// 2 elevado a 0 es 1, por lo que es potencia
	if (n == 1)
		return (1);
	// si no existe n o es impar, devuelve 0
	if (!n || (n % 2) != 0)
		return (0);
	return (1);
}
/*
int  main()
{
	printf("%i\n",is_power_of_2(-2));
	printf("%d\n", is_power_of_2(11));
	return (0);
}
*/
