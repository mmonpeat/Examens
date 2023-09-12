/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:12:16 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/27 17:31:27 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int *tab array d'ints
// unsigned int len numero d'elements al array
int max(int *tab, unsigned int len)
{
	int res = tab[0];
	unsigned int i = 0;

	while (i < len)
	{
		if (res < tab[i])
				res = tab[i];
		i++;
	}
	return (res);
}
/*
int main(void) {
    int array[] = {5, 10, 2, 9998, 3};
    int len = sizeof(array) / sizeof(array[0]); // obtenim la longitud de l'array

    int max_val = max(array, len);
    printf("El valor màxim de l'array és: %d\n", max_val);

    return 0;
}*/
