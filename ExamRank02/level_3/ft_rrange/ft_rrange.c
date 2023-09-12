/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:35:01 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 16:11:07 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int *ft_rrange(int start, int end)
{
	int *res = NULL;
	int i;
	int len = ft_abs(end - start) + 1;

	i = 0;
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (start < end)
		{
			res[i] = end;
			printf("%i ", res[i]);
			end--;
			i++;
		}
		else
		{
			res[i] = end;
			printf("%i ", res[i]);
			end++;
			i++;
		}
	}
	return (res);
}
/*
int main(void)
{
	ft_rrange(0,-3);
	return (0);
}*/
