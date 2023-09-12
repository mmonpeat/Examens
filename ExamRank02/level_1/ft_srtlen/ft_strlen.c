/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:18 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/20 13:13:37 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i =0;
	while(str[i] != '\0')
		i++;
	return (i);
}

/*int main ()
{
    char str[] = "Holiwis mon";
    int res = ft_strlen(str);
	printf("%i", res);
    return (0);
}*/
