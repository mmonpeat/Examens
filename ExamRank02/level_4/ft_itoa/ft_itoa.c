/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:27:54 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/11 17:55:53 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_itoa(int num);
static int ft_numlen(int num);
static int ft_abs(int num);

/*int main(void)
{
	int num;

	num = 24;
	printf("num int: %s", ft_itoa(num));
	return (0);
}*/

char	*ft_itoa(int num)
{
	char	*res;
	int		len;

	len = ft_numlen(num);
	res =  (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';//len es 2 si el num es 24 pero com es un array comenca a contar en 0 pt posicio 2 es el 3r espai
	if (num < 0)
		res[0] = '-';
	else if (num == 0)
		res[0] = '0';
	while (num)
	{
		--len;//aixi no conta el '\0' anterior
		res[len] = ft_abs(num % 10) + '0';//en la penutima pos poses 24 % 10 = 4 en caracter
		num /= 10;//si encara hi ha num despres de 24/10= es a dir 2, pt entra al bucle i no entrara quan 2/10=0
	}
	return (res);
}

static int ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		++len;
		num /= 10;
	}
	return (len);
}

static int ft_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}
