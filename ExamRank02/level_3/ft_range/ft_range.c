/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:31:19 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 15:47:21 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdlib.h>
#include <stdio.h>

int ft_abs(int n);

int *ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs((end - start)) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);

	res[len] = '\0';
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			//printf("%i\n", res[i]);
			start--;
			i++;
		}
	}
    return (res);
}

int ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
/*
int main()
{
ft_range(0, -3);

	return (0);
}*/
